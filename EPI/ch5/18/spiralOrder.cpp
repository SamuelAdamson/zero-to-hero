#include <iostream>
#include <vector>


/**
 * @brief Output the spiral order of the input square matrix (2d array)
 * @param a (guaranteed square)
 */
void spiralOrder(const std::vector<std::vector<int>>& a) {
    int sr = 0, er = a.size() - 1, sc = 0, ec = a.size() - 1; 
    int i, j;

    while(sr <= er || sc <= ec) {
        for(i = sr, j = sc; j <= ec; j++) std::cout << a[i][j] << std::endl;
        sr++;

        for(i = sr, j = ec; i <= er; i++) std::cout << a[i][j] << std::endl;
        ec--;

        for(i = er, j = ec; j >= sc; j--) std::cout << a[i][j] << std::endl;
        er--;

        for(i = er, j = sc; i >= sr; i--) std::cout << a[i][j] << std::endl;
        sc++;
    }

}

int main() {
    // Test cases
    std::vector<std::vector<int>> t1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> t2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    spiralOrder(t1);
    spiralOrder(t2);
}