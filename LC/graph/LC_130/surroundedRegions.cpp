class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O') {
            board[r][c] = 'V';
            dfs(board, r-1, c, m, n);
            dfs(board, r, c-1, m, n);
            dfs(board, r+1, c, m, n);
            dfs(board, r, c+1, m, n);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0, m, n);
            if(board[i][n-1] == 'O') dfs(board, i, n-1, m, n);
        }
        
        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') dfs(board, 0, i, m, n);
            if(board[m-1][i] == 'O') dfs(board, m-1, i, m, n);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
            }
        }
    }
};