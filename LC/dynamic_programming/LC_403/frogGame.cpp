class Solution {
private:
    bool helper(
        const vector<int> &stones,
        const unordered_map<int, int> &stoneMap,
        vector<vector<int>> &dp,
        int i, int k, int n
    ) {
        if(i == n-1) return true; // last stone
        if(dp[i][k] != -1) return dp[i][k];
        
        bool nextReachable = false;
        for(int j = max(1, k-1); j <= k+1 && !nextReachable; j++) {
            if(stoneMap.find(stones[i] + j) == stoneMap.end()) continue;
            int nextI = stoneMap.at(stones[i] + j); // index of new stone
            nextReachable = helper(stones, stoneMap, dp, nextI, j, n);
        }

        return dp[i][k] = nextReachable;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size(), i;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // 2D dp matrix
        unordered_map<int, int> stoneMap;   // map stone to index

        for(i = 0; i < n; i++)
            stoneMap[stones[i]] = i;
        
        return helper(stones, stoneMap, dp, 0, 0, n);
    }
};