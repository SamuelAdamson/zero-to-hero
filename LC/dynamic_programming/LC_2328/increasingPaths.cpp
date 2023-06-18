class Solution {
private:
    const int MOD_VAL = 1e9 + 7;

    long long dfs(
        const vector<vector<int>> &grid, 
        vector<vector<bool>> &v,
        vector<vector<long long>> &dp,
        int i, int j, int m, int n, int last
    ) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] >= last) return 0;
        if(v[i][j]) return dp[i][j];
        v[i][j] = true;

        dp[i][j] = (dp[i][j] + dfs(grid,v,dp,i-1,j,m,n,grid[i][j])) % MOD_VAL;
        dp[i][j] = (dp[i][j] + dfs(grid,v,dp,i+1,j,m,n,grid[i][j])) % MOD_VAL;
        dp[i][j] = (dp[i][j] + dfs(grid,v,dp,i,j-1,m,n,grid[i][j])) % MOD_VAL;
        dp[i][j] = (dp[i][j] + dfs(grid,v,dp,i,j+1,m,n,grid[i][j])) % MOD_VAL;

        return dp[i][j];
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j;
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<long long>> dp(m, vector<long long>(n, 1));

        long long res = 0;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                res = (res + dfs(grid,visited,dp,i,j,m,n,1e6)) % MOD_VAL;
            }
        }

        return res;
    }
};