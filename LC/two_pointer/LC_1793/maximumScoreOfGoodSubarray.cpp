class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minVal = nums[k], best = nums[k];
        int l = k, r = k, n = nums.size();

        while(!(l == 0 && r == n-1)) {
            if(l == 0) r++;
            else if(r == n-1) l--;
            else if(nums[l-1] < nums[r+1]) r++;
            else l--;

            minVal = min(minVal, nums[l]);
            minVal = min(minVal, nums[r]);
            best = max(best, minVal * (r - l + 1));
        }

        return best;
    }
};
