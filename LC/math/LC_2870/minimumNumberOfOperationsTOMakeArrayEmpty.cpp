class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> fMap;
        for(int n : nums)
            fMap[n]++;
        
        int result = 0;
        for(auto p : fMap) {
            if(p.second == 1) return -1;
            
            result += (p.second / 3);
            if(p.second % 3 != 0) result++;
        }
        
        return result;
    }
};