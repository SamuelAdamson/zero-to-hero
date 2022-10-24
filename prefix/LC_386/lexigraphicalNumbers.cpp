class Solution {
public:
    void dfs(string& curr, int n, vector<int>& result) {
        result.push_back(stoi(curr));

        for(int i = 0; i <= 9; i++) {
            curr.push_back(i+'0');
            if(stoi(curr) <= n) dfs(curr, n, result);
            curr.pop_back();
        }
    }    
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        string curr = "";
        
        for(int i = 1; i <= min(9, n); i++) {
            curr.push_back(i+'0');
            dfs(curr, n, result);
            curr.pop_back();
        }
        
        return result;
    }
};