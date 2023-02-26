class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size(), n = word2.size(), i = 0, j = 0, a = 0, b = 0;
        
        while(i < m && j < n) {
            while(a < word1[i].size() && b < word2[j].size()) {
                if(word1[i][a] != word2[j][b]) return false;
                a++, b++;    
            }
            if(a >= word1[i].size()) i++, a = 0;
            if(b >= word2[j].size()) j++, b = 0;
        }
        
        if(i < m || j < n) return false;
        return true;
    }
};