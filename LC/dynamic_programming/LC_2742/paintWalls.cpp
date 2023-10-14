class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = time.size(), i, j, timeSum = time[0]+1;
        
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for(j = 1; j <= min(n, timeSum); j++) 
            dp[j] = cost[0];

        for(i = 1; i < n; i++) {
            vector<int> n_dp(n+1, -1);
            n_dp[0] = 0;
            
            timeSum += time[i] + 1;

            for(j = 0; j < min(n, timeSum); j++) {
                if(dp[j+1] == -1)
                    n_dp[j+1] = cost[i] + dp[max(j-time[i], 0)];
                else
                    n_dp[j+1] = min(dp[j+1], cost[i] + dp[max(j-time[i], 0)]);
            }

            dp = n_dp;
        }

        return dp[n];
    }
};
