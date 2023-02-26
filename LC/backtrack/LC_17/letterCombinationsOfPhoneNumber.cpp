class Solution {
public:
    // Add 2 to index
    vector<string> letterMap = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void backtrack(vector<string>& result, string& curr, string& digits, int s, int n) {
        if(s == n) result.push_back(curr);
        else {
            for(char c : letterMap[digits[s]-'0' - 2]) {
                curr.push_back(c);
                backtrack(result, curr, digits, s + 1, n);
                curr.pop_back();
            }   
        }   
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curr;
        int n = digits.length();
        
        if(n > 0) backtrack(result, curr, digits, 0, n);
            
        return result;
    }
};