class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = 10e5+1, l = 0, r = 0, currSum = 0;
        
        while(r < nums.size()) {
            currSum += nums[r];
            while(l <= r && currSum >= target) {
                minSize = min(minSize, r-l+1);
                currSum -= nums[l];
                l++;
            }
            
            r++;
        }
        
        return minSize != (10e5+1) ? minSize : 0;
    }
};