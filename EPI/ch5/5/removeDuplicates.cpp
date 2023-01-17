#include <iostream>
#include <vector>

/**
 * @brief Remove all duplicates from the vector, and shift unique
 *  elements to leftmost position in the array.
 * @param v 
 */
void removeDuplicates(std::vector<int> &v) {
    int n = v.size(), l, r;

    for(l = 0, r = 1; r < n; r++) {
        if(v[r] > v[l]) {
            v[l+1] = v[r];
            l++;
        }
    }
}

int main() {
    // Test cases
    std::vector<int> t1 = {2, 3, 5, 5, 7, 11, 11, 11, 13};

    removeDuplicates(t1);
    
    for(int i = 0; i < t1.size(); i++) std::cout << t1[i] << " ";
    std::cout << std::endl;
}