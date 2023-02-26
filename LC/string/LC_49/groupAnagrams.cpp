class Solution {
public:
    string pseudoSort(string s) {
        // Linear time
        
        vector<int> freqMap(26);
        string sorted = "";
        
        for(char ch : s) freqMap[ch - 'a']++;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < freqMap[i]; j++) {
                sorted.push_back(i + 'a');
            }
        }
        
        return sorted;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;
        
        for(int i = 0; i < strs.size(); i++) {
            groups[pseudoSort(strs[i])].push_back(strs[i]);
        }
        
        for(pair<string, vector<string>> p : groups) {
            result.push_back(p.second);
        }
        
        return result;
    }
};