class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int currFlipped = 0, best = 0;
        int l = 0, r = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) {
                while(l <= r && currFlipped >= k) {
                    if(nums[l++] == -1)
                        currFlipped--;
                }

                nums[r] = -1;
                currFlipped++;
            }

            r++;
            best = max(best, r - l);
        }

        return best;
    }
};

