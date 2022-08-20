class Solution {
public:   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*  Find the nearest distance to each 0 for each cell.
            Note that the matrix is connected 4-directionally.
        
            Find all zero coordinates, and store in queue. Perform BFS from 
            these cells simultaneously, only traversing to non-zero cells.
            Mark distance as level of bfs.
        */
        int m = mat.size(), n = mat[0].size(), level = 0;
        
        vector<vector<int>> result(m, vector<int>(n, 0)); // Resultant matrix
        queue<pair<int, int>> q;  // Queue for bfs
        
        vector<pair<int, int>>  directions ({{-1, 0}, {0, -1}, {1, 0}, {0, 1}});
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) q.push({i, j});
            }
        }
        
        
        while(!q.empty()) {
            int sz = q.size();
            level++;
            
            for(int k = 0; k < sz; k++) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                for(pair direction: directions) {
                    int i = row + direction.first, j = col + direction.second;
                    
                    if(i >= 0 && i < m && j >= 0 && j < n && mat[i][j] == 1) {
                        q.push({i, j});
                        
                        result[i][j] = level;
                        mat[i][j] = -1;
                    }
                }
            }
        }
        
        
        return result;
    }
};