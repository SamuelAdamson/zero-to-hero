#include <iostream>
#include <vector>


/**
 * @brief Rotate array 90 degrees in place
 * @param a (guaranteed square)
 */
void rotateArray(std::vector<std::vector<int>>& a) {
    int i, j, n = a.size()-1;
    int t1, t2, t3;

    for(i = 0; i < n/2+1; i++) {
        for(j = i; j < n-i; j++) {
            t1 = a[j][n-i];
            t2 = a[n-i][n-j];
            t3 = a[n-j][i];

            a[j][n-i] = a[i][j];
            a[n-i][n-j] = t1;
            a[n-j][i] = t2;
            a[i][j] = t3;
        }
    }
}

int main() {
    // Test cases
    std::vector<std::vector<int>> t1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateArray(t1);
    for(int i = 0; i < t1.size(); i++) {
        for(int n : t1[i]) std::cout << n << " ";
        std::cout << std::endl;
    }
}