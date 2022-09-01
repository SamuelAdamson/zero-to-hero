class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*  Length of longesty substring without repeating 
            characters.
            
            Sliding window plus hash map approach. Keep two pointers 
            left index of substring and right index of substring. 
            Iterate until right is at end of string. As a character is
            added to the substring, add into map that character and the index 
            of its occurrence. As each new character is added, check map first, 
            if that character is present, move left up to that character, dropping
            all previous characters from map.
        */
        int l = 0, r = 1, n = s.length(), maxLen = 1, existing;
        if(n < 2) return n;
        
        unordered_map<char, int> chars({{s[l], l}});
        while(r < n) {
            if(chars.find(s[r]) != chars.end()) {
                existing = chars[s[r]];
                while(l <= existing) chars.erase(s[l++]);
            } 
                
            chars[s[r]] = r;
            r++;
            maxLen = max(maxLen, r - l);
        }
        
        return maxLen;
    }
};