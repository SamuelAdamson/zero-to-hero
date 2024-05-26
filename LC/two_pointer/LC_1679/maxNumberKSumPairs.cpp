class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, sum;
        int result = 0;

        sort(nums.begin(), nums.end());

        while(r >= l && nums[r] >= k) r--;
        while(l < r) {
            sum = nums[l] + nums[r];

            if(sum == k) result++, l++, r--;
            else if(sum > k) r--;
            else l++;
        }

        return result;
    }
};

