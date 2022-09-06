class Solution {
public:
    void backtrack(string& s, int i, vector<string>& permutations) {
        if(i < s.length()) {
            if(isalpha(s[i])) {
                s[i] = tolower(s[i]);
                backtrack(s, i + 1, permutations);
                
                s[i] = toupper(s[i]);
                backtrack(s, i + 1, permutations);
            }
            else {
                backtrack(s, i + 1, permutations);       
            }
        }
        else {
            permutations.push_back(s);   
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> permutations;
        backtrack(s, 0, permutations);
        
        return permutations;
    }
};