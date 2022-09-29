class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& candidates, int s, int n, int currSum, int target) {
        unordered_set<int> used;
        
        if(currSum == target) result.push_back(curr);
        for(int i = s; i < n; i++) {
            if(currSum + candidates[i] <= target && used.find(candidates[i]) == used.end()) {
                curr.push_back(candidates[i]);
                used.insert(candidates[i]);
                
                backtrack(result, curr, candidates, i+1, n, currSum + candidates[i], target);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        
        backtrack(result, curr, candidates, 0, candidates.size(), 0, target);
        
        return result;
    }
};