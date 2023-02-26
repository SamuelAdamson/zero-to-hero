class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 1, maxSize = 0;
        int numZeros = 0, lastZero;
        if(nums[0] == 0) numZeros = 1, lastZero = 0;
        
        while(r < nums.size()) {
            if(nums[r] == 0) {
                numZeros++;
                if(numZeros > 1) {
                    l = lastZero+1;
                    numZeros--;
                }
                lastZero = r;
            }
            
            maxSize = max(maxSize, r - l);
            r++;
        }
        
        return maxSize;
    }
};