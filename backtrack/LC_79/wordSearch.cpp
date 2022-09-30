class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int i, int j, int m, int n, string& word, int k) {
        // i : current row of board
        // j : current column of board
        // k : current index in word
        if(k == word.length()) return true;
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) return false;
        
        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '0';
        
        bool left = backtrack(board, i, j-1, m, n, word, k+1);
        bool above = backtrack(board, i-1, j, m, n, word, k+1);
        bool right = backtrack(board, i, j+1, m, n, word, k+1);
        bool below = backtrack(board, i+1, j, m, n, word, k+1);
        
        // Unmark visited
        board[i][j] = temp;
        
        return left || above || right || below;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(backtrack(board, i, j, m, n, word, 0)) return true;
            }
        }
        
        return false;
    }
};