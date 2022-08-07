class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int nRows, int nCols, int row, int col) {
        if(row >= 0 && row < nRows && col >= 0 && col < nCols) { // In Bounds
            if(grid[row][col] == 0) {
                grid[row][col] = -1;
                
                return ( // Single ampersand so all functions execute
                    dfs(grid, nRows, nCols, row-1, col) &
                    dfs(grid, nRows, nCols, row, col-1) &
                    dfs(grid, nRows, nCols, row+1, col) &
                    dfs(grid, nRows, nCols, row, col+1)
                );
            }
            else {
                return true;
            }
        }
        else { // Out of bounds, we are at an edge so return false
            return false; 
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        /* 1 -> Water
           0 -> Land
           Closed island is a group of 0's completely surrounded by 1's.
           
           Traverse each connected group of 0's, if the graph leads to an edge,
           that island is not closed. If the graph leads to a one in ALL directions,
           return true.
        */
        int nRows = grid.size(), nCols = grid[0].size();
        int closed = 0;
        
        for(int i = 1; i < nRows-1; i++) {
            for(int j = 1; j < nCols-1; j++) {
                if(grid[i][j] == 0) {
                    closed += dfs(grid, nRows, nCols, i, j);
                }
            }
        }
        
        return closed;
    }
};