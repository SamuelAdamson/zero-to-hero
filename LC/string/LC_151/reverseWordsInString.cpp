class Solution {
public:
    vector<string> split(string s) {
        string curr = "";
        vector<string> result;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' || i == s.length() - 1) {
                if(s[i] != ' ') curr.push_back(s[i]); 
                if(curr.length()) result.push_back(curr);
                curr = "";
            }
            else {
                curr.push_back(s[i]);
            }
        }
        
        return result;
    }
    
    string reverseWords(string s) {
        vector<string> words = split(s);
        string result = ""; 
        
        for(int i = words.size() - 1; i >= 0; i--) {
            result.append(words[i]);
            if(i) result.push_back(' ');
        }
        
        return result;
    }
};