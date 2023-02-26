class Solution {
public:
    vector<int> bfs(vector<vector<int>>& g, int i, int j, int m, int n) {
        vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q ({{i, j}});
        vector<int> result{i, j};

        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            
            // update result
            result[0] = max(result[0], row);
            result[1] = max(result[1], col);

            for(auto dir : dirs) {
                int nRow = row + dir.first, nCol = col + dir.second;
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && g[nRow][nCol]) {
                    q.push({nRow, nCol});
                    g[nRow][nCol] = 0;
                }
            }
        }

        return result;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j]) {
                    vector<int> start = {i, j}; // store top left
                    vector<int> end = bfs(land, i, j, m, n);

                    start.insert(start.end(), end.begin(), end.end());
                    result.push_back(start);
                }
            }
        }

        return result;
    }
};