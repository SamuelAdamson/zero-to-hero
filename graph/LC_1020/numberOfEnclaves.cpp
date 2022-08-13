class Solution {
public:
    void dfs(vector<vector<int>>& grid, int m, int n, int row, int col) {
        if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
            grid[row][col] = -1;
            
            dfs(grid, m, n, row-1, col);
            dfs(grid, m, n, row, col-1);
            dfs(grid, m, n, row+1, col);
            dfs(grid, m, n, row, col+1);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        /*  We want to find land cells (1's) that are not connected to boundary.
        
            Iterate through edges, do DFS (or BFS) on each edge, marking all
            1's as visited, then iterate through grid counting 1's.
        */
        
        int m = grid.size(), n = grid[0].size();
        int enclaves = 0;
        
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                dfs(grid, m, n, i, 0);
            }
            if(grid[i][n-1] == 1) {
                dfs(grid, m, n, i, n-1);
            }
        }
        
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1) {
                dfs(grid, m, n, 0, j);
            }
            if(grid[m-1][j] == 1) {
                dfs(grid, m, n, m-1, j);
            }
        }
        
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                enclaves += grid[i][j] == 1;
            }
        }
        
        return enclaves;
    }
};