class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, 
             int currHeight, int m, int n, int row, int col) {
        if(row >= 0 && row < m && col >= 0 && col < n && heights[row][col] >= currHeight && !visited[row][col]) {
            visited[row][col] = 1;
            
            dfs(heights, visited, heights[row][col], m, n, row-1, col);
            dfs(heights, visited, heights[row][col], m, n, row, col-1);
            dfs(heights, visited, heights[row][col], m, n, row+1, col);
            dfs(heights, visited, heights[row][col], m, n, row, col+1);
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       /*   Finding cells that can reach both atlantic and pacific ocean
            ([bottom and right frame] and [top and left frame] respectively).
            Water can only flow to cells that are less than or equal to.
            
            Start from atlantic and pacific cells, perform dfs to cells
            that are GREATER than or equal to (working backwards so reverse relationship).
            Mark these cells as visited, return cells that are visited by both
            pacific and atlantic oceans.
       */
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == m-1 || j == n-1) dfs(heights, atlantic, heights[i][j], m, n, i, j);
                if(i == 0 || j == 0) dfs(heights, pacific, heights[i][j], m, n, i, j); 
            }
        }
                
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(atlantic[i][j] && pacific[i][j]) result.push_back({i,j});
            }
        }
    
        return result;
    }
};