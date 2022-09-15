class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n - 1;
        
        int l = 1, r = n - 2, m, peak = -1;
        
        while(l <= r && peak == -1) {
            m = l + (r - l)/2;
            
            if(nums[m] > nums[m-1] && nums[m] > nums[m+1]) peak = m;
            else if(nums[m] < nums[m + 1]) l = m + 1;
            else r = m - 1;
        }
        
        return peak;
    }
};