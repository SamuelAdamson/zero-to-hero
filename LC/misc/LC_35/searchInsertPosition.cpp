class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*  Return index of target if it is in sorted array nums.
            If target is not in array, return the index where it should be.
            
            Use binary search. If it's not found, then return the position
            where it should be.
        */
        int n = nums.size();
        int l = 0, r = n - 1, mid = n - 1;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            
            if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        
        return nums[mid] < target ? mid + 1 : mid;
    }
};