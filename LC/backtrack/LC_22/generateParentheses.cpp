class Solution {
public:
    void backtrack(vector<string>& result, string& curr, int n, int open, int close) {
        if(open == n && close == n) result.push_back(curr);
        else {
            if(open < n) {
                curr.push_back('(');
                backtrack(result, curr, n, open + 1, close);
                curr.pop_back();
            }
            if(close < open) {
                curr.push_back(')');
                backtrack(result, curr, n, open, close + 1);
                curr.pop_back();
            }   
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> result;
        string curr = "(";
        
        backtrack(result, curr, n, 1, 0);
        
        return result;
    }
};