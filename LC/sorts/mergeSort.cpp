#include <vector>
using namespace std;

/*
    Implementation of merge sort
    This is my go-to sorting algorithm, if required during 
        a competition / interview
*/


void merge(vector<int>& v, int l, int m, int r) {
    // Create two subarrays to store values for merge
    int i = 0, j = 0, k = l;
    vector<int> left(m - l + 1), right(r - m);

    // Populate vectors for merge
    for(int i = l; i <= m; i++) left[i - l] = v[i];
    for(int i = m + 1; i <= r; i++) right[i - (m + 1)] = v[i];

    // Merge lists while values left in both right and left
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            v[k] = left[i];
            i++;
        }
        else {
            v[k] = right[j];
            j++;
        }

        // Next index in merged list
        k++;
    }

    // Empty lists
    while(i < left.size()) {
        v[k] = left[i];
        k++, i++;    
    }
    
    while(j < right.size()) {
        v[k] = right[j];
        k++, j++;   
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if(l < r) {
        // Get mid point
        int m = l + (r - l) / 2;

        // Recursive call on each half
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        // Merge together lists
        merge(v, l, m, r);
    }
}