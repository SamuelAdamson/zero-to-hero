class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes.size(), n = votes[0].size();
        vector<vector<int>> ranks(26, vector<int>(n+1));
        string result = "";
        
        // Put character in last position for each rank
        for(int i = 0; i < n; i++) ranks[votes[0][i] - 'A'][n] = votes[0][i];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ranks[votes[i][j] - 'A'][j]--;
            }
        }
        
        sort(ranks.begin(), ranks.end());
        for(int i = 0; i < n; i++) {
            result.push_back(ranks[i][n]);
        }
        
        return result;
    }
};