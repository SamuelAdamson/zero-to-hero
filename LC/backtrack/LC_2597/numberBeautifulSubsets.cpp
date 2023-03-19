class Solution {
public:
    int res;
    vector<int> s;    
    
    void backtrack(const vector<int> &nums, int i, int k) {
        for(int j = i; j < nums.size(); j++) {
            if((nums[j]+k < 1001 && s[nums[j]+k]) || (nums[j]-k >= 0 && s[nums[j]-k])) continue;
            
            res++;
            
            s[nums[j]] = 1;
            backtrack(nums, j+1, k);
            s[nums[j]] = 0;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        res = 0;
        s = vector<int>(1001);
        
        backtrack(nums, 0, k);
        return res;
    }
};