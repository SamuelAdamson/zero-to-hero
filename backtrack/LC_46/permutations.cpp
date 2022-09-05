class Solution {
public:
    void backtrack(vector<int>& nums, int begin, vector<vector<int>>& result)	{
		if (begin >= nums.size()) {
		    result.push_back(nums);
		}
		else {
            for (int i = begin; i < nums.size(); i++) {
                swap(nums[begin], nums[i]);
                backtrack(nums, begin + 1, result);
                swap(nums[begin], nums[i]);
            }   
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        /*  Given an array of integers, return all possible 
            permutations of said array.
            
            We can employ backtracking here, by selecting a value, and 
            then taking the permutations of the subarray which excludes 
            the selected value.
        */
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        
        return result;
    }
};