class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int l = 0, r = 0;

        while(r < nums.size()) {
            if(!nums[r]) res += (r - l + 1), r++;
            else l = ++r;
        }

        return res;
    }
};