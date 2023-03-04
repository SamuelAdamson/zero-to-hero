class Solution {
public:
    int uniquePaths(int m, int n) {
        int left, above = 1;

        for(int i = 1; i < m; i++) { // i rows
            for(int j = 1; j < n; j++) dp[j] += dp[j-1];
        }

        return dp[n-1];
    }
};