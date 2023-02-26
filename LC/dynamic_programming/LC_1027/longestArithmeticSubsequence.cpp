class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp (nums.size(), vector<int>(1001));
        int maxLen = 2, currDiff;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                currDiff = nums[i]-nums[j] + 500;
                dp[i][currDiff] = (dp[j][currDiff] > 0) ? dp[j][currDiff] + 1 : 2;
                maxLen = max(maxLen, dp[i][currDiff]);
            }
        }
        
        
        return maxLen; 
    }
};