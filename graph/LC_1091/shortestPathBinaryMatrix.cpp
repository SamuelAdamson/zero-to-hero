class Solution {
public:
    int bfs(vector<vector<int>>& grid, int n, int row, int col) {
        // Returns level that bottom left is reached, or -1
        queue<tuple<int,int>> q ({{row, col}});
        grid[row][col] = -1;
        
        int level = 0;
        bool bottomReached = false;
        
        while(!q.empty() && !bottomReached) {
            int sz = q.size();
            level++;
            
            for(int k = 0; k < sz && !bottomReached; k++) {
                int row = get<0>(q.front()), col = get<1>(q.front());
                q.pop();

                if(row == n-1 && col == n-1) bottomReached = true;
                else {
                    for(int i = row-1; i <= row+1; i++) {
                        for(int j = col-1; j <= col+1; j++) {
                            if(i >= 0 && i < n && j >= 0 && j < n && !grid[i][j]) {
                                q.push({i, j});
                                grid[i][j] = -1; // Putting this here, ensures we don't queue repeats
                            }
                        }
                    }   
                }
            }
            
        }
        
        if(bottomReached) return level;
        else return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        /*  Find the shortest path through the 2d matrix, where each
            cell is connected 8-directionally. Start at top left finish at 
            bottom right.
            
            Perform bfs on the graph, keeping track of the level. The level
            at which the bottom right is reached is the length of the shortest
            path.
        */
        int n = grid.size();
        
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        return bfs(grid, n, 0, 0);
    }
};