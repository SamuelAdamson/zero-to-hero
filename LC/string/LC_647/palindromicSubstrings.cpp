class Solution {
public:
    
    int isPalindrome(string& s, int l, int r) {
        int n = s.length(), count = 0;
        
        while(l >= 0 && r < n && s[l] == s[r]) {
            count++;
            r++;
            l--;
        }
        
        return count;
    }
    
    int countSubstrings(string s) {
        int total = 0;
        
        for(int i = 0; i < s.length(); i++) {
            total += isPalindrome(s, i, i);
            total += isPalindrome(s, i, i+1);
        }
        
        return total;
    }
};