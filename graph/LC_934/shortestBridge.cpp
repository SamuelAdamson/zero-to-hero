class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>> q, int n, int toVisit, int toFind) {
        vector<pair<int,int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int level = 0, qSize;
        bool found = false;
        
        while(!q.empty() && !found) {
            qSize = q.size();
            level++;
            
            for(int k = 0; k < qSize; k++) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                for(pair<int,int> dir: directions) {
                    int row = i + dir.first, col = j + dir.second;
                    
                    if(row >= 0 && row < n && col >= 0 && col < n) {
                        if(grid[row][col] == toFind) found = true;
                        else if(grid[row][col] == toVisit) {
                            grid[row][col] = -1;
                            q.push({row, col});
                        }
                    }
                }
            }
            
        }
        
        return level - 1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        /*  0 represents water, 1 represents land. There are exactly 
            2 islands. Find the fewest number of 1's needed to be flipped 
            to connect the two islands.
            NOTE: land is connected 4-directionally.
            
            [[0 1 0]
             [0 0 0]
             [0 0 1]]
            
            Iterate through the board and find a 1 (an island square). Perform 
            BFS on this square to mark all of its islands as visited. Add all squares 
            on this first island to the queue. Then perform, bfs on all squares in the first 
            island simultaneously. When the new island is encountered, return the level of the 
            bfs.
        */
        queue<pair<int, int>> q;
        bool firstIsland = false;
        int n = grid.size(), distance;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!firstIsland && grid[i][j] == 1) {
                    firstIsland = true;
                    grid[i][j] = -1;
                    
                    q.push({i, j});
                    bfs(grid, q, n, 1, 2);
                }
                else if(grid[i][j] == -1) {
                    q.push({i, j});
                }
            }
        }

        
        distance = bfs(grid, q, n, 0, 1);
        return distance;
    }
};