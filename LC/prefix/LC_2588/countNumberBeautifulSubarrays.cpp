class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0;
        int mask = 0;
        unordered_map<int, int> xorMap({{0, 1}});
        
        for(int n : nums) {
            mask ^= n;
            res += xorMap[mask];
            
            xorMap[mask]++;
        }
        
        return res;
    }
};