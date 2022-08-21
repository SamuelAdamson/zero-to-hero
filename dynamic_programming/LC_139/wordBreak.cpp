class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*  Given a list of words, and a string, determine if the 
            string can be some combination of one or more words in the 
            word list.
        
            Working backwards in the string, at each index, determine if
            the substring for this index forward can be work broken (breaked?).
            If it can, we know that if we can reach that index, from the start 
            of the string, then the entire string can be word broken. 
        */
        int n = s.size();
        int m = wordDict.size(), wordSize;
        bool match;
        
        vector<bool> dp (n+1, false);
        dp[n] = true;
        
        
        for(int i = n-1; i >= 0; i--) { // i : index in string s
            for(int j = 0; j < m; j++) {
                wordSize = wordDict[j].length();
                
                if(i + wordSize <= n && !dp[i]) {    
                    match = true;
                    for(int l = 0; l < wordSize && match; l++) {
                        if(wordDict[j][l] != s[i + l]) match = false;
                    }
                    
                    dp[i] = match && dp[i + wordSize];
                }
            }
        }
        
        return dp[0];
    }
};