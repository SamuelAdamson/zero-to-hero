class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*  Search for target using binary search.
            
            -1 0 3 5 9 12
            
            We want to basically split the array in half
            at check. If the target is greater than the mid point, 
            then shift the midpoint down, etc.
        */
        int n = nums.size();
        int l = 0, r = n-1, mid;
        bool found = false;
        
        while(l <= r && !found) {
            mid = l + (r-l)/2;
            
            if(nums[mid] > target) r = mid-1;
            else if(nums[mid] < target) l = mid+1;
            else found = true;
        }
        
        return found ? mid : -1;
    }
};