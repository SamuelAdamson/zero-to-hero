class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& candidates, int s, int n, int currSum, int target) {
        if(currSum == target) result.push_back(curr);
        
        for(int i = s; i < n; i++) {
            if(currSum + candidates[i] <= target) {
                curr.push_back(candidates[i]);
                backtrack(result, curr, candidates, i, n, currSum + candidates[i], target);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        backtrack(result, curr, candidates, 0, candidates.size(), 0, target);
        
        return result;
    }
};