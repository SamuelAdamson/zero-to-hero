class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int currMax = -1;
        
        for(int num : nums) set.insert(num);
        for(int num : set) {
            if(num > currMax && set.find(-num) != set.end()) currMax = num;
        }
        
        return currMax;
    }
};