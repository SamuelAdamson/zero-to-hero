class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = nums.size()-1;
        
        for(int l = 0; l < r; l++) {
            if(nums[r] > 1) r--, l--;
            else if(nums[l] > 1) {
                swap(nums[l], nums[r]);
                r--;
            }
        }
        
        for(int l = 0; l < r; l++) {
            if(nums[r] > 0) r--, l--;
            else if(nums[l] > 0) {
                swap(nums[l], nums[r]);
                r--;
            }
        }
    }
};