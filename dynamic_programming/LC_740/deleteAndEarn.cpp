class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int nMax = 10e4, best = 0;
        
        vector<int> values(nMax, 0);
        for(int num : nums) values[num] += num;
        
        for(int i = 1; i < nMax; i++) {
            if(i < 2) {
                values[i] = max(values[i], values[i-1]);
            }
            else {
                values[i] = max(values[i] + values[i-2], values[i-1]);
            }
        }
        
        return values[nMax-1];
    }
};