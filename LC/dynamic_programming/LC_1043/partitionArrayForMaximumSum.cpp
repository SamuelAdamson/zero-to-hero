class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        /*  Partition array for maximum sum. Given an integer array, 
            find the maximum sum, if the array can be partitioned into 
            contiguious subarrays of size <= k and each value in that 
            subarray is changed to the maximum of said subarray.
        
            Iterate through array, maintaining a dp table. The ith index 
            of the dp table should be:
                dp[i - k] + max(current subarray) * k
                
            
        */
        int n = arr.size(), currMax = 0, best = 0;
        vector<int> dp (n + 1);
        
        for(int i = 1; i <= n; i++) {
            currMax = 0, best = 0;
            
            for(int j = 1; j <= k && i - j >= 0; j++) {
                currMax = max(currMax, arr[i - j]);
                best = max(best, dp[i - j] + currMax * j);
            }
            dp[i] = best;
        }
        
        return dp[n];
    }
};