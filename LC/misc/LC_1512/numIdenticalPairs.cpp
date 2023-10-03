class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0, i = 0;
        vector<int> fMap(101);

        while(i < nums.size()) {
            result += fMap[nums[i]];
            fMap[nums[i]]++;
            
            i++;
        }

        return result;
    }
};