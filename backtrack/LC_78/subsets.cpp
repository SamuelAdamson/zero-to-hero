class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& nums, int s, int n) {
        result.push_back(curr);
        for(int i = s; i < n; i++) {
            curr.push_back(nums[i]);
            backtrack(result, curr, nums, i + 1, n);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        
        backtrack(result, curr, nums, 0, nums.size());
        
        return result;
    }
};