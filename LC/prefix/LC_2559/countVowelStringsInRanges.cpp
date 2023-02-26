class Solution {
public:
    int valid(char c) {
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return 1;
            default:
                return 0;
        }
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> result, dp(words.size());
        dp[0] = valid(words[0][0]) && valid(words[0][words[0].size()-1]);
        
        for(int i = 1; i < words.size(); i++)
            dp[i] = dp[i-1] + (valid(words[i][0]) && valid(words[i][words[i].size()-1]));
        
        for(int i = 0; i < queries.size(); i++){
            if(!queries[i][0]) result.push_back(dp[queries[i][1]]);
            else result.push_back(dp[queries[i][1]] - dp[queries[i][0]-1]);
        }
        
        return result;
    }
};