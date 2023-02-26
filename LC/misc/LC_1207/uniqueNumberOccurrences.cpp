class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> occur;
        
        for(int n : arr) m[n]++;
        for(pair<int, int> p : m) if(!occur.insert(p.second).second) return false;
        
        return true;
    }
};