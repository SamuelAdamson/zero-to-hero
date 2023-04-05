class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        vector<int> rows(m), cols(n);
        
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(grid[i][j]) rows[i]++, cols[j]++;
                else rows[i]--, cols[j]--;
            }
        }

        vector<vector<int>> res(m, vector<int>(n));
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                res[i][j] = rows[i] + cols[j];
            }
        }

        return res;
    }
};