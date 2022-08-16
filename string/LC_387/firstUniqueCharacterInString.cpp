class Solution {
public:
    int firstUniqChar(string s) {
        /*  Find index of first non-repeating character.
            
            Create a vector to act as a map (26 long for 26 alpha characters).
            Populate map with frequencies of characters. First character
            with 1 occurrence is returned.
        */
        int index = -1;
        vector<int> letters (26, 0);
        
        for(char letter: s) {
            letters[letter - 'a'] ++;
        }
        
        for(int i = 0; i < s.length() && index == -1; i++) {
            if(letters[s[i] - 'a'] == 1) index = i;
        }
            
        
        return index;
    }
};