class Solution {
private:
    void backtrack(
        vector<vector<string>> &res, 
        vector<string> &board, 
        vector<int> &cols, 
        vector<int> &tr_bl,
        vector<int> &tl_br,
        int n
    ) {
            if(board.size() == n) res.push_back(board);
            else {
                for(int i = 0; i < n; i++) {
                    if(cols[i] || tr_bl[i + board.size()] || tl_br[i - board.size() + (n-1)]) continue;

                    string row(n, '.');
                    row[i] = 'Q';

                    cols[i] = 1;
                    tr_bl[i + board.size()] = 1;
                    tl_br[i - board.size() + (n-1)] = 1;
                    
                    board.push_back(row);
                    backtrack(res, board, cols, tr_bl, tl_br, n);
                    board.pop_back();

                    cols[i] = 0;
                    tr_bl[i + board.size()] = 0;
                    tl_br[i - board.size() + (n-1)] = 0;
                }
            }
        }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;

        // hashing diagonals
        // tr_bl : (row + col)
        // tl_br : (col - row + (n-1))
        vector<int> cols(n), tr_bl(2 * n - 1), tl_br(2 * n - 1);
        
        backtrack(res, board, cols, tr_bl, tl_br, n);
        return res;
    }
};