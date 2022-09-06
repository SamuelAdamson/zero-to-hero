class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), minPath;    
        vector<int> dp ({triangle[0]});
        
        for(int i = 1; i < n; i++) {
            vector<int> level ({triangle[i][0] + dp[0]});
            
            for(int j = 1; j < triangle[i].size() - 1; j++) {
                level.push_back(min(triangle[i][j] + dp[j - 1], triangle[i][j] + dp[j]));
            }
            
            level.push_back({triangle[i][i] + dp[i - 1]});
            dp = level;
        }
        
        minPath = dp[0];
        for(int path : dp)
            minPath = min(minPath, path);
        
        return minPath;
    }
};