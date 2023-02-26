class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), peaks = 1, valleys = 1;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) valleys = peaks + 1;
            else if(nums[i] < nums[i-1]) peaks = valleys + 1;
        }
        
        return max(peaks, valleys);
    }
};