class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m, sz;
        while(l < r) {
            m = l + (r - l) / 2;
            sz = r - m;
            
            if(sz & 1) { // odd
                if(nums[m] == nums[m+1]) r = m-1;
                else l = m+1;
            }
            else { // even
                if(nums[m] == nums[m+1]) l = m+1;
                else r = m;
            }
        }

        return nums[l];
    }
};