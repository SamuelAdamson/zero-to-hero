class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& paths, vector<pair<int, int>>& dirs, int r, int c) {
        if(r == grid.size()-1 && c == grid[0].size()-1) return true;
        int path = grid[r][c] - 1;
        grid[r][c] = -1; // Mark visited
        
        for(int i = 0; i < 4; i++) {
            if(paths[path][i]) {
                int newR = r + dirs[i].first;
                int newC = c + dirs[i].second;

                if(newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && grid[newR][newC] != -1) {
                    int j = (i % 2 == 0) ? i + 1 : i - 1;
                    if(paths[grid[newR][newC] - 1][j] && dfs(grid, paths, dirs, newR, newC)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        // left, right, up, down
        vector<vector<bool>> paths({
            {true, true, false, false},
            {false, false, true, true},
            {true, false, false, true},
            {false, true, false, true},
            {true, false, true, false},
            {false, true, true, false}
        });
        
        // left, right, up, down
        vector<pair<int, int>> dirs({
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        });
        
        return dfs(grid, paths, dirs, 0, 0);
    }
};