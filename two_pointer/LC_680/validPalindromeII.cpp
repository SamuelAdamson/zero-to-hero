class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        
        while(l < r) {
            if(s[l] != s[r]) {
                if(isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1)) return true;
                return false;
            }
            l++, r--;
        }
        
        return true;
    }
};