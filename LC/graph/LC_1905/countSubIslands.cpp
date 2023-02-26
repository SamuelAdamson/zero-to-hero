class Solution {
public:
    bool dfs(
        vector<vector<int>>& grid1, vector<vector<int>>& grid2,
        int m, int n, int row, int col
    ) {
        if(row < 0 || row >= m || col < 0 || col >= n || grid2[row][col] != 1) return true;
        grid2[row][col] = -1;
        
        bool subIsland = grid1[row][col] == 1;
        subIsland &= dfs(grid1, grid2, m, n, row-1, col);
        subIsland &= dfs(grid1, grid2, m, n, row, col-1);
        subIsland &= dfs(grid1, grid2, m, n, row+1, col);
        subIsland &= dfs(grid1, grid2, m, n, row, col+1);
        
        return subIsland;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        /*  Sub island : an island in grid 2 where all the cells that make up the
            island are included in an island on grid 1.
            NOTE: grid 1 and grid 2 have the same dimensions.
            
            So, we iterate and conduct dfs on grid 2, if we encounter an island that 
            is not included in an island on grid 1, then return false.
        */
        int m = grid2.size(), n = grid2[0].size();
        int subIslands = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid2[i][j] == 1) subIslands += dfs(grid1, grid2, m, n, i, j);
                
        return subIslands;
    }
};