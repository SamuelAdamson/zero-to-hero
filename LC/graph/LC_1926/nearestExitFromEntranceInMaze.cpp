class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        /*  Given a maze represented as a 2d array. Empty cells (travel-able) 
            are marked with a '.', while wall cells are marked with a '+'. Find 
            the shortest path from the entrance to an exit (empty cell that is on border).
            NOTE: the entrance cannot be an exit.
            
            Find all potential exits, perform simultaneous bfs working towards the starting point. 
            If the starting point is reached, then return the level of the traverse. Otherwise, 
            we return negative one
        */
        int m = maze.size(), n = maze[0].size(), level = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool found = false;
        
        for(int i = 0; i < m; i++) {
            if(maze[i][0] == '.' && !(i == entrance[0] && entrance[1] == 0)) q.push({i, 0});
            if(maze[i][n-1] == '.' && !(i == entrance[0] && entrance[1] == n-1)) q.push({i, n-1});
        }
        for(int j = 0; j < n; j++) {
            if(maze[0][j] == '.' && !(j == entrance[1] && entrance[0] == 0)) q.push({0, j});
            if(maze[m-1][j] == '.' && !(j == entrance[1] && entrance[0] == m-1)) q.push({m-1, j});
        }
        
        
        while(!q.empty() && !found) {
            int sz = q.size();
            level++;
            
            for(int k = 0; k < sz; k++) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                for(pair<int, int> dir : directions) {
                    int i = row + dir.first, j = col + dir.second;
                    
                    if(i >= 0 && i < m && j >= 0 && j < n) {
                        if(i == entrance[0] && j == entrance[1]) found = true;
                        else if(maze[i][j] == '.') {
                            maze[i][j] = 'v';
                            q.push({i, j});   
                        }
                    }
                }
            }
        }
        
        return found ? level : -1;
    }
};