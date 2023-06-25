class Solution {
private:
    const int MOD_VAL = 1e9 + 7;

    long long dfs(
        const vector<int> &locations, 
        vector<vector<int>> &dp,
        int s, int e, int fuel, int n
    ) {
        if(fuel < 0) return 0;
        if(fuel == 0) return s == e;
        if(dp[s][fuel-1] != -1) return dp[s][fuel-1];

        long long res = s == e;
        for(int i = 0; i < n; i++) {
            if(i == s) continue;
            res = (
                res + dfs(locations, dp, i, e, fuel - abs(locations[s] - locations[i]), n)
            ) % MOD_VAL;
        }

        dp[s][fuel-1] = res;
        return res;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size(), i;
        vector<vector<int>> dp(n, vector<int>(fuel, -1));

        return dfs(locations, dp, start, finish, fuel, n);
    }
};