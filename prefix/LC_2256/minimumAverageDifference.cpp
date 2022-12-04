class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), idx = 0, best = 1e5, curr = 0;
        long long preSum = 0, suffSum = 0;
        for(int num : nums) suffSum += num;
        
        for(int i = 0; i < n-1; i++) {
            preSum += nums[i];
            suffSum -= nums[i];
            
            curr = abs(preSum/(i+1) - suffSum/(n-i-1));
            if(curr < best) idx = i, best = curr;
        }
        
        return ((preSum + nums[n-1])/n < best) ? n-1 : idx;
    }
};