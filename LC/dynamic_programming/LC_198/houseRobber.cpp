class Solution {
public:
    int rob(vector<int>& nums) {
        /* Maximize sum of subset of array, cannot choose adjacent values
           
           Iterate through the array, store the maxmimum possible amount
           at each step.
        */
        
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(i < 2) {
                nums[i] = max(nums[i-1], nums[i]);
            }
            else {
                nums[i] = max(nums[i-1], nums[i] + nums[i-2]);   
            }
        }
        
        return nums[n-1];
    }
};