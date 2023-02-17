class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players (ages.size());
        for(int i = 0; i < ages.size(); i++) players[i] = {ages[i], scores[i]};

        // sort descending
        sort(players.begin(), players.end());
        vector<int> dp(ages.size());
        int best = 0, i, j;

        for(i = 0; i < ages.size(); i++) {
            dp[i] = players[i].second;
            for(j = 0; j < i; j++) {
                if(players[i].second >= players[j].second) 
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            best = max(dp[i], best);
        }

        return best;
    }
};