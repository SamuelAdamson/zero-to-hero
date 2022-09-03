class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*  Given a 4-directionally connected grid where 
                2 -> rotting orange
                1 -> fresh orange
                0 -> empty cell
            determine how many minutes it takes for every orange to become rotten 
            if a fresh orange only lasts a minute near a rotting orange.
            
            Locate every rotten orange, and perform BFS to each fresh orange keeping
            track of the current level. If any orange is left fresh afterwards, return -1.
        */
        vector<pair<int,int>> directions ({{-1, 0}, {0, -1}, {1, 0}, {0, 1}});
        int m = grid.size(), n = grid[0].size(), level = -1, sz;
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
               if(grid[i][j] == 2) q.push({i, j});
            }   
        }
        
        while(!q.empty()) {
            sz = q.size();
            level++;
            
            for(int k = 0; k < sz; k++) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                for(pair<int, int> dir : directions) {
                    int i = row + dir.first, j = col + dir.second;
                    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                    }
                }
            }
        }        
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
               if(grid[i][j] == 1) return -1;
            }   
        }
        
        return (level == -1) ? 0 : level;
    }
};