class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int numSubArrs = 0, l = 0, r = 0, currProd = 1;
        
        while(r < nums.size()) {
            currProd *= nums[r];
            if(currProd < k) numSubArrs+=(r-l+1);
            else {
                while(l < r && currProd >= k) {
                    currProd /= nums[l];
                    l++;
                }
                if(currProd < k) numSubArrs+=(r-l+1);
            }
            
            r++;
        }
        
        return numSubArrs;
    }
};