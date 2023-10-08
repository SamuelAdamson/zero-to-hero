class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        unsigned n = nums1.size(), m = nums2.size(), i, j;
        vector<int> c_dp(n, INT_MIN);
        vector<int> r_dp(m, INT_MIN);

        // fill out borders of dp
        c_dp[0] = r_dp[0] = nums1[0] * nums2[0];  
        for(j = 1; j < m; j++) r_dp[j] = max(r_dp[j-1], nums1[0] * nums2[j]);
        for(i = 1; i < n; i++) c_dp[i] = max(c_dp[i-1], nums1[i] * nums2[0]);

        for(i = 1; i < n; i++) {
            vector<int> dp(m);
            dp[0] = c_dp[i];

            for(j = 1; j < m; j++) {
                dp[j] = max(dp[j-1], r_dp[j]);
                dp[j] = max(dp[j], r_dp[j-1]);

                int p = nums1[i] * nums2[j];
                dp[j] = max(dp[j], p);
                dp[j] = max(dp[j], r_dp[j-1] + p);
            }

            r_dp = dp;
        }

        return r_dp[m-1];
    }
};
