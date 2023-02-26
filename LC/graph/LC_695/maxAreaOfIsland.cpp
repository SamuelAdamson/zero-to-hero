class Solution {
public:
    int dfs(vector<vector<int>>& grid, int nRows, int nCols, int row, int col, int area) {
        if(row >= 0 && row < nRows && col >= 0 && col < nCols && grid[row][col]==1) {
            grid[row][col] = 0;
            area++;
            
            area = dfs(grid, nRows, nCols, row-1, col, area);
            area = dfs(grid, nRows, nCols, row, col-1, area);
            area = dfs(grid, nRows, nCols, row+1, col, area);
            area = dfs(grid, nRows, nCols, row, col+1, area);
        }
        
        return area;
    }
    
    int bfs(vector<vector<int>>& grid, int nRows, int nCols, int row, int col) {
        int area = 0;
        
        queue<tuple<int,int>> toVisit;
        toVisit.push(make_tuple(row, col));
        
        while(!toVisit.empty()) {
            tuple<int,int> coordinate = toVisit.front();
            int i = get<0>(coordinate), j = get<1>(coordinate);
            toVisit.pop();
            
            if(i >= 0 && i < nRows && j >= 0 && j < nCols && grid[i][j] == 1) {
                grid[i][j] = 0;
                area++;
                
                toVisit.push(make_tuple(i-1, j));
                toVisit.push(make_tuple(i, j-1));
                toVisit.push(make_tuple(i+1, j));
                toVisit.push(make_tuple(i, j+1));
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /* General idea is similar to previous island problems. Traverse graph
           and mark islands as visited. Compute and store max area of islands.
           
           Use DFS or BFS to traverse graph.
        */
        
        
        int nRows = grid.size(), nCols = grid[0].size();
        int maxArea = 0;
        
        for(int i = 0; i < nRows; i++) {
            for(int j = 0; j < nCols; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, nRows, nCols, i, j, 0));
                    // maxArea = max(maxArea, bfs(grid, nRows, nCols, i, j));
                }        
            }
        }
        
        return maxArea;
    }
};