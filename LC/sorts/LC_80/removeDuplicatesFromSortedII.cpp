class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l, r, curr = nums[0], cnt = 1;

        for(l = 0, r = 1; r < nums.size(); r++) {
            if(nums[r] == curr) cnt++;
            else {
                curr = nums[r];
                cnt = 1;
            }

            if(cnt <= 2) nums[++l] = curr;
        }

        return l + 1;
    }
};