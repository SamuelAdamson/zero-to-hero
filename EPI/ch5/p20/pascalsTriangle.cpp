#include <iostream>
#include <vector>

/**
 * @brief Output the first n rows of pascal's triangle.
 *  Each entry is the sum of adjacent entries above (consider the centered output).
 * @param n 
 * @return std::vector<std::vector<int>> 
 */
std::vector<std::vector<int>> pascalsTriangle(int n) {
    if(!n) return {{}};

    // Note the return type requires O(n^2) storage, however,
    //  in our computations we are really only using the row above
    //  so in theory O(n) storage
    std::vector<std::vector<int>> result = {{1}};
    int row;
    
    for(row = 1; row < n; row++) {
        std::vector<int> next = {1};

        for(int i = 1; i < row; i++) {
            next.push_back(result[row-1][i-1] + result[row-1][i]);
        }

        next.push_back(1);
        result.push_back(next);
    }

    return result;
}

int main() {
    // Test cases
    int t1 = 5;
    int t2 = 10;

    std::vector<std::vector<int>> r1 = pascalsTriangle(t1);
    for(int i = 0; i < r1.size(); i++) {
        for(int n : r1[i]) std::cout << n << " ";
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> r2 = pascalsTriangle(t2);
    for(int i = 0; i < r2.size(); i++) {
        for(int n : r2[i]) std::cout << n << " ";
        std::cout << std::endl;
    }
}