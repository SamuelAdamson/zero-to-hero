class Solution {
private:
    const int MOD_VAL = 1e9 + 7;
    
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int lastOne, i;
        long long ways = 0;
        
        for(i = 0; i < nums.size(); i++) {
            if(nums[i]) {
                if(!ways) ways = 1;
                else if(lastOne < i - 1) {
                    ways = (ways * (i - lastOne)) % MOD_VAL;
                }
                
                lastOne = i;
            }
        }
        
        return ways;
    }
};