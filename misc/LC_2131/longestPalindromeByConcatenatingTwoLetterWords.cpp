class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int maxLen = 0;
        vector<vector<int>> freqMap (26, vector<int>(26));
        
        for(string word : words) {
            if(freqMap[word[1]-'a'][word[0]-'a'] > 0) {
                maxLen += 4;
                freqMap[word[1]-'a'][word[0]-'a']--;   
            }
            else {
                freqMap[word[0]-'a'][word[1]-'a']++;
            }
        }
        
        for(int i = 0; i < freqMap.size(); i++) {
            if(freqMap[i][i]) return maxLen + 2;
        }
        
        return maxLen;
    }
};