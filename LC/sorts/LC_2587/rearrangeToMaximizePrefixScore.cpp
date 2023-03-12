class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long prefix = 0;
        int cnt = 0, i;
        
        for(i = 0; i < nums.size() && prefix >= 0; i++) {
            prefix += nums[i];
            if(prefix > 0) cnt++;
        }
        
        return cnt;
    }
};