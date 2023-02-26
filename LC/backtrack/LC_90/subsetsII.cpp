class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& nums, int s, int n) {
        unordered_set<int> used;
        
        for(int i = s; i < n; i++) {
            curr.push_back(nums[i]);
            
            if(used.find(nums[i]) == used.end()) {
                result.push_back(curr);
                used.insert(nums[i]);
                backtrack(result, curr, nums, i + 1, n);
            }
            
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result({{}});
        vector<int> curr;
        sort(nums.begin(), nums.end());
        
        backtrack(result, curr, nums, 0, nums.size());
        
        return result;
    }
};