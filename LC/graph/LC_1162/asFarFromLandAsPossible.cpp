class Solution {
public:
    
    void addToQueue(queue<pair<int, int>>& q, vector<vector<int>>& grid, int row, int col, int n) {
        if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0) {
            grid[row][col] = -1;
            q.push({row, col});   
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        /*  Find the maximum distance from a water cell to a land cell.
            Note we use Manhatten distance, so distance between (x0, y0) and
            (x1, y1) is |x0-x1| + |y0-y1|. 
            
            Consider the grid as a 4-directionally connected graph. Perform BFS
            to count the number of levels from which a water block is from 
        */
        bool waterFound = false;
        int maxDist = -1, n = grid.size(), level;
        queue<pair<int, int>> q;
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) q.push({i,j});
                else waterFound = true;
            }
        }
        
        while(!q.empty()) {
            maxDist++;
            level = q.size(); // Size of current level from land cells
            
            for(int i = 0; i < level; i++) {
                auto front = q.front();
                q.pop();
                int row = front.first, col = front.second;
                
                addToQueue(q, grid, row-1, col, n);
                addToQueue(q, grid, row, col-1, n);
                addToQueue(q, grid, row+1, col, n);
                addToQueue(q, grid, row, col+1, n);
            }
        }
        
        
        if(!waterFound) return -1;
        return maxDist;
    }
};