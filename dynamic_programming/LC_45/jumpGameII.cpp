class Solution {
public:
    int jump(vector<int>& nums) {
        /*  Similar to Jump Game 1. Starting at first index, you can
            jump a maximum of nums[i] places, find minimum number of jumps to
            reach end.
            NOTE: We can always reach the end.
            
            So, start iterating from right, and store the minimum number of jumps
            at each step.
        */
        int large = 10e7;
        int n = nums.size(), currMin;
        
        for(int i = n-1; i >= 0; i--) {
            if(i == n-1) nums[i] = 0;
            else if(i + nums[i] >= n-1) nums[i] = 1;
            else {
                currMin = large;
                for(int j = 1; j <= nums[i]; j++) {
                    currMin = min(nums[i + j], currMin);
                }
                nums[i] = currMin + 1;
            }
        }
        
        return nums[0];
    }
};