class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum = 0, m = grid.size(), n = grid[0].size(), currBest;
        
        for(int i = 0; i < m; i++) sort(grid[i].begin(), grid[i].end());
        
        for(int j = n-1; j >= 0; j--) {
            currBest = 0;
            for(int i = 0; i < m; i++) currBest = max(grid[i][j], currBest);
            sum += currBest;
        }
        
        return sum;
    }
};