class Solution {
public:
    bool checkPermutation(vector<int>& a, vector<int>& b) {
        // assumes a and b 26 long
        
        bool permutation = true;
        for(int i = 0; i < 26 && permutation; i++) {
            if(a[i] != b[i]) permutation = false;
        }
        
        return permutation;
    }
    
    bool checkInclusion(string s1, string s2) {
        /*  Check if s2 has a substring which is a permuation of s1.
        
            So, to start off create a frequency map of s1 where each 
            character is a key and the value is number of occurrences.
            Then, iterate through s2 with a fixed-width sliding window. Maintain 
            a second frequency map for the current substring of s2. If all chars 
            are matching, return true
        */
        int n = s2.length(), s1Len = s1.length();
        if(n < s1Len) return false;
        
        bool permutation = false;
        int l = 0, r = s1Len - 1;
        
        vector<int> s1Freq (26, 0), s2Freq(26, 0);
        for(char c : s1) s1Freq[c-'a']++;
        for(int i = 0; i < s1Len - 1; i++) s2Freq[s2[i]-'a']++;
        
        while(r < n && !permutation) {
            s2Freq[s2[r]-'a']++;
            permutation = checkPermutation(s1Freq, s2Freq);
            
            s2Freq[s2[l]-'a']--;
            l++;
            r++;
        }
        
        return permutation;
    }
};