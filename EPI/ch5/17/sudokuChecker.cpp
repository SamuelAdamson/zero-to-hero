#include <iostream>
#include <vector>


bool checkRow(const std::vector<std::vector<int>>& sudoku, int i) {
    if(sudoku[i].size() != 9) return false;
    std::vector<bool> used(9);
    
    for(int n : sudoku[i]) {
        if(n && used[n]) return false;
        used[n] = true;
    }

    return true;
}

bool checkColumn(const std::vector<std::vector<int>>& sudoku, int i) {
    std::vector<bool> used(9);

    for(int j = 0; j < 9; j++) {
        if(sudoku[j][i] && used[sudoku[j][i]]) return false;
        used[sudoku[j][i]] = true;
    }

    return true;
}

bool checkRegion(const std::vector<std::vector<int>>& sudoku, int i) {
    std::vector<bool> used(9);
    int sr = (i/3) * 3, sc = (i % 3) * 3, j;

    for(i = sr; i < sr + 3; i++) {
        for(j = sc; j < sc + 3; j++) {
            if(sudoku[i][j] && used[sudoku[i][j]]) return false;
            used[sudoku[i][j]] = true;
        }
    }

    return true;
}

/**
 * @brief Validates that a partial sudoku board has no duplicates.
 * @param sudoku 
 * @return true 
 * @return false 
 */
bool checkSudoku(const std::vector<std::vector<int>>& sudoku) {
    for(int i = 0; i < 9; i++) {
        if(!(checkRow(sudoku, i) && checkColumn(sudoku, i) && checkRegion(sudoku, i))) return false;
    }

    return true;
}

int main() {
    // Test cases
    std::vector<std::vector<int>> t1 = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    std::vector<std::vector<int>> t2 = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 1},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    std::cout << "Test 1: " << checkSudoku(t1) << std::endl;
    std::cout << "Test 2: " << checkSudoku(t2) << std::endl;
}