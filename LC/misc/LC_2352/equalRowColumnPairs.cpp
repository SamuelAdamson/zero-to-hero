class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        size_t n = grid.size(), i, j;
        int result = 0;
        unordered_map<string, int> col_map(n);
        
        for(j = 0; j < n; j++) {
            string col;

            for(i = 0; i < n; i++) {
                col.append(to_string(grid[i][j]));
                col.push_back(',');
            }

            col_map[col]++;
        }

        for(i = 0; i < n; i++) {
            stringstream ss;
            copy(grid[i].begin(), grid[i].end(), ostream_iterator<int>(ss, ","));

            result += col_map[ss.str()];
        }
        
        return result;
    }
};
