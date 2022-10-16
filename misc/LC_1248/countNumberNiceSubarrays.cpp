class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, numOdd = 0, subCount = 0, result = 0;
        
        while(r < nums.size()) {
            if(nums[r] & 1) {
                numOdd++;
                subCount = 0;
            }
            
            while(numOdd == k) {
                if(nums[l] & 1) numOdd--;
                l++, subCount++;
            }
            
            result += subCount;
            r++;
        }
        
        return result;
    }
};