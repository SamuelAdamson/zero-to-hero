class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i == m) return j;
        
        if(grid[i][j] == -1) {
            if(j == 0 || grid[i][j-1] == 1) return -1;
            return dfs(grid, i+1, j-1, m, n);
        } 
        else {
            if(j == n-1 || grid[i][j+1] == -1) return -1;
            return dfs(grid, i+1, j+1, m, n);
        } 
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) result[i] = dfs(grid, 0, i, m, n);
        
        return result;
    }
};