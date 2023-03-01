class Solution {
private:

    void backtrack(vector<vector<int>> &v, vector<int> &nums, int i) {
        if(i == nums.size()) v.push_back(nums);
        else {
            vector<int> used(21);

            for(int j = i; j < nums.size(); j++) {
                if(used[nums[j]+10]) continue;
                else {
                    used[nums[j]+10] = 1;

                    swap(nums[j], nums[i]);
                    backtrack(v, nums, i+1);
                    swap(nums[j], nums[i]);
                }
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        backtrack(v, nums, 0);
        return v;
    }
};