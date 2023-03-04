class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), i, j;
        bool fr = false, fc = false;

        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if(i == 0) fr = true;
                    if(j == 0) fc = true;
                }
            }
        }

        for(i = 1; i < m; i++) {
            for(j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }
        
        if(fr)
            for(j = 1; j < n; j++) matrix[0][j] = 0;

        if(fc)
            for(i = 1; i < m; i++) matrix[i][0] = 0;
    }
};