class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || k - 1 + maxPts <= n) return 1.0;
        
        vector<double> dp(n+1);
        dp[0] = 1.0;

        double result = 0.0, probSum = 1.0;
        for(int i = 1; i <= n; i++) {
            dp[i] = probSum / maxPts;

            if(i < k) // have not reached end condition
                probSum += dp[i];
            else
                result += dp[i];

            if(i - maxPts >= 0)
                probSum -= dp[i - maxPts];
        }

        return result;
    }
};