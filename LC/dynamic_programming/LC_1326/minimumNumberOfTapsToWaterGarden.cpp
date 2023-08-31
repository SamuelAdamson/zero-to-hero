class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int m = n+1, i;
        vector<pair<int,int>> intervals(m);
        
        for(i = 0; i < m; i++)
            intervals[i] = { max(i - ranges[i], 0), min(i + ranges[i], n) };

        sort(intervals.begin(), intervals.end());
        
        vector<int> dp(m);
        int j = 0;

        for(i = 0; i < m && j < n; i++) {
            if(intervals[i].first > j) return -1; // gap
            if(intervals[i].second > j) {
                int take = dp[intervals[i].first] + 1;
                while(j < intervals[i].second)
                    dp[++j] = take;
            }
        }

        if(j < n) return -1;
        return dp[n];
    }
};
