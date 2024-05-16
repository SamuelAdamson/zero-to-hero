class Solution {
private:
    size_t n;

    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };

    void bfs(
        vector<vector<int>> &paths,
        vector<vector<int>> &grid
    ) {
        queue<pair<int, int>> q;
        int dist = 1, k, i, j;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(grid[i][j]) {
                    q.push({ i, j });
                    paths[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            for(k = q.size(); k > 0; k--) {
                pair<int, int> cell = q.front();
                q.pop();

                for(auto const &dir : dirs) {
                    int r = cell.first + dir.first;
                    int c = cell.second + dir.second;

                    if(r >= n || r < 0 || c >= n || c < 0 || paths[r][c] != -1) 
                        continue;

                    q.push({ r, c });
                    paths[r][c] = dist;
                }
            }

            dist++;
        }
    }


public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> paths(n, vector<int>(n, -1));

        /* Perform BFS from every thief */
        bfs(paths, grid);

        /* Find maximized minimum distance to nearest thief */
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({ paths[0][0], {0, 0} });
        
        vector<vector<bool>> v(n, vector<bool>(n, false));
        v[0][0] = true;
        
        while(!pq.empty()) {
            int safeness = pq.top().first;
            pair<int, int> source = pq.top().second;
            pq.pop();

            if(source.first == n-1 && source.second == n-1) return safeness;
            
            for(auto const &dir : dirs) {
                int r = source.first + dir.first;
                int c = source.second + dir.second;

                if(r < 0 || r >= n || c < 0 || c >= n || v[r][c]) continue;

                int newSafeness = min(safeness, paths[r][c]);
                pq.push({newSafeness, { r, c }});
                v[r][c] = true;
            }
        }

        return 0;
    }
};

