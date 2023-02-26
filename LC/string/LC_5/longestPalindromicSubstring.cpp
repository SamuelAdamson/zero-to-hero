class Solution {
public:
    pair<int,int> findPalindrome(string s, int l, int r) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return make_pair(l+1, r-l-1);
    }
    
    string longestPalindrome(string s) {
        int maxLen = 0;
        pair<int,int> centered, offCenter;
        pair<int, int> best;
        
        for(int i = 0; i < s.length(); i++) {
            centered = findPalindrome(s, i, i);
            offCenter = findPalindrome(s, i, i+1);
            
            if(centered.second > maxLen) {
                best = centered;
                maxLen = centered.second;
            }
            if(offCenter.second > maxLen) {
                best = offCenter;
                maxLen = offCenter.second;
            }
        }
        
        return s.substr(best.first, maxLen);
    }
};