class Solution {
public:
    bool checkAnagram(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < 26; i++) if(a[i] != b[i]) return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        
        int l = 0, r = p.length() - 1, n = s.length();
        vector<int> pChars(26), currChars(26), result;
        
        for(int i = 0; i < p.length(); i++) {
            pChars[p[i]-'a']++;
            if(i < r) currChars[s[i]-'a']++;
        }
        
        while(r < n) {
            currChars[s[r]-'a']++;
            if(checkAnagram(pChars, currChars)) result.push_back(l);
            
            currChars[s[l]-'a']--;
            l++, r++;
        }
        
        return result;
    }
};