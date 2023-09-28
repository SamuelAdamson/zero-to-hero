class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, i = 0;

        while(i < nums.size()) {
            if(!(nums[i] & 1))
                swap(nums[i], nums[l++]);
            
            i++;
        }

        return nums;
    }
};