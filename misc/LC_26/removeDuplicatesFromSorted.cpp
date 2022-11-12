class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j, n = nums.size();
        
        for(i = 1, j = 1; i < n && j < n; i++) {
            if(nums[i] <= nums[i-1]) {
                while(j < n && nums[j] <= nums[i-1]) j++;
                if(j < n) swap(nums[i], nums[j++]);
                else i--;
            }
        }
        
        return i;
    }
};