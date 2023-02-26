class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size(), s = 0, i;
        vector<int> answer(n);
        
        for(i = 0; i < n; i++) {
            answer[i] = s;
            s += nums[i];
        }
        
        s = 0;
        for(i = n-1; i >= 0; i--) {
            answer[i] = abs(answer[i] - s);
            s += nums[i];
        }
        
        return answer;
    }
};