#include <vector>
using namespace std;


vector<int> merge(vector<int>& v, int l1, int h1, int l2, int h2) {

}

void mergeSort(vector<int>& v, int l, int h) {
    int n = h - l + 1;

    if(h - l > 1) {
        int l1 = l, h1 = l + n / 2;
        int l2 = l + n/2 + 1, h2 = h;

        mergeSort(v, l1, h1);
        mergeSort(v, l2, h2);

        merge(v, l1, h1, l2, h2);
    }
}