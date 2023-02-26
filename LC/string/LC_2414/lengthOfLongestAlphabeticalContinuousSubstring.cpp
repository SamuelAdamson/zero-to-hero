class Solution {
public:
    int longestContinuousSubstring(string s) {
        int l = 0, maxLen = 1;
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] - s[i-1] != 1) l = i;
            maxLen = max(maxLen, i - l + 1);
        }
        
        return maxLen;
    }
};