class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*  Maximum subarray of circular array. The array is circular
            such that the element following the last is the first.
            NOTE: a subarray may only contain each element in the array once.
            
            In the case that the maximum sum is not changed by the fact that
            the array is circular, we can use standard Kadane's. Outside of Kadane's
            we can simply take the total sum and subtract the minimum contiguous subarray.
            Keep track of min and max sum's.
            
            One caveat, if the maximum sum is negative, that means all values in array
            are negative, so the total sum minus the minimum sum will result in a 
            value of 0.
        */
        int minSum = nums[0], maxSum = nums[0], totalSum = 0;
        int currMin = 0, currMax = 0;
        
        for(int num : nums) {
            totalSum += num;
            currMin = min(currMin + num, num);
            currMax = max(currMax + num, num);
            minSum = min(currMin, minSum);
            maxSum = max(currMax, maxSum);
        }
        
        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};