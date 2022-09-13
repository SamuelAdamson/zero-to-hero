class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        int start = -1, end = -1;
        
        
        while(l < r) {
            mid = l + (r - l)/2;
            
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(nums.size() == 0 || nums[l] != target) return {start, end};
        start = l;
        
        
        r = nums.size() - 1;
        while(l < r) {
            mid = (l+1) + (r - l)/2;
            
            if(nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        end = r;
        
        return {start, end};
    }
};