class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int map = 0;
        for(int n : nums) map ^= n;

        return map;
    }
};