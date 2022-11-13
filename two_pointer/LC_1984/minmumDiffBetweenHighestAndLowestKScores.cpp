class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l, r, best = 1e5;
        
        for(l = 0, r = k - 1; r < nums.size(); r++, l++) 
            best = min(best, nums[r] - nums[l]);
        
        return best;
    }
};