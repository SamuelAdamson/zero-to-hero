class Solution {
public:
    void dfs(vector<vector<char>>& grid, int nRows, int nCols, int row, int col) {
        if(row >= 0 && row < nRows && col >= 0 && col < nCols && grid[row][col] == '1') {
            grid[row][col] = 'V';
            dfs(grid, nRows, nCols, row-1, col);
            dfs(grid, nRows, nCols, row, col-1);
            dfs(grid, nRows, nCols, row+1, col);
            dfs(grid, nRows, nCols, row, col+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        /* 1 -> Land
           0 -> Water
            
           Find islands, assuming the edges of graph are surrounded by water.
           Islands are NOT connected diagonally.
           
           Use DFS to traverse graph, only traversing cells that are marked 1.
           Mark each cell as visited 'V'.
        */
        
        int nRows = grid.size(), nCols = grid[0].size();
        int numIslands = 0;
        
        for(int i = 0; i < nRows; i++) {
            for(int j = 0; j < nCols; j++) {
                if(grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, nRows, nCols, i, j);
                }
            }
        }
        
        return numIslands;
    }
};