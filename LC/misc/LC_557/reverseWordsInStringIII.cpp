class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(), l = 0, r;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ' || i == n-1) {
                r = i == n-1 ? i : i-1;
                while(l < r) {
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }
                l = i + 1;
            }
        }
        
        return s;
    }
};