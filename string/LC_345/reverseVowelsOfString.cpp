class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        unordered_set<char> vowels ({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        char temp;
        
        while(l < r) {
            if(vowels.count(s[l]) && vowels.count(s[r])) {
                temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++, r--;
            }
            else {
                if(!vowels.count(s[l])) l++;
                if(!vowels.count(s[r])) r--;
            }
        }
        
        return s;
    }
};