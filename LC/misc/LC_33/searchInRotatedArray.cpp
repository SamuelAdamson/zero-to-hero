class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, m, pivot, pivotMid;      
        
        // First find pivot point
        while(l < r) {
            m = l + (r - l)/2;
            
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        pivot = l;
        
        l = 0, r = n - 1;
        while(l <= r) {
            m = l + (r - l)/2;
            pivotMid = (m + pivot) % n;
            
            if(nums[pivotMid] == target) return pivotMid;
            
            if(nums[pivotMid] < target) l = m + 1;
            else r = m - 1;
        }
        
        return -1;
    }
};