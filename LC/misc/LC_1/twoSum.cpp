class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        vector<int> result(2);
        bool found = false;
        
        for(int i = 0; i < nums.size() && !found; i++) {
            if(index.find(target - nums[i]) != index.end()) {
                found = true;
                result[0] = index[target - nums[i]];
                result[1] = i;
            }
            index[nums[i]] = i;
        }
        
        return result;
    }
};