class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, ind, r, c;
        std::vector<int> used(9);
        
        // check rows
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                ind = board[i][j]-'0'-1;

                if(used[ind]) return false;
                used[ind] = 1;
            }
            fill(used.begin(), used.end(), 0);
        }

        // check columns
        for(j = 0; j < 9; j++) {
            for(i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                ind = board[i][j]-'0'-1;

                if(used[ind]) return false;
                used[ind] = 1;
            }
            fill(used.begin(), used.end(), 0);
        }

        // check boxes
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                r = 3 * (i/3) + j/3;
                c = 3 * (i%3) + j%3;

                if(board[r][c] == '.') continue;
                ind = board[r][c]-'0'-1;

                if(used[ind]) return false;
                used[ind] = 1;
            }
            fill(used.begin(), used.end(), 0);
        }

        return true;
    }
};