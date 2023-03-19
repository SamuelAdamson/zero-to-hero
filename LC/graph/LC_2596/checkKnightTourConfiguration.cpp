class Solution {
public:
    bool dfs(const vector<vector<int>> &grid, int r, int c, int move, int n, int last) {
        if(r >= n || r < 0 || c >= n || c < 0 || grid[r][c] != move) return false;
        if(move == last) return true;
        
        int next = move+1;
        return (dfs(grid, r+2, c+1, next, n, last) || 
                dfs(grid, r+2, c-1, next, n, last) ||
                dfs(grid, r-2, c+1, next, n, last) ||
                dfs(grid, r-2, c-1, next, n, last) ||
                dfs(grid, r+1, c+2, next, n, last) ||
                dfs(grid, r-1, c+2, next, n, last) ||
                dfs(grid, r+1, c-2, next, n, last) ||
                dfs(grid, r-1, c-2, next, n, last));
        
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, 0, grid.size(), grid.size()*grid.size()-1);
    }
};