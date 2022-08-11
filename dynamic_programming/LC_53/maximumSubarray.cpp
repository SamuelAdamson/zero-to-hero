class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*  Maximum contiguous subarray of array.
            
            Iterate through array, and at each position consider
            extending the current sum, or taking just the current number
            as the current sum (reset current sum). Store maximum sum
            after each position.
        */
        
        
        int currSum = 0, maxSum = nums[0];
        
        for(int num: nums) {
            currSum = max(currSum + num, num);
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum;
    }
};