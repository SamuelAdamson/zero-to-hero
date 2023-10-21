class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        unsigned n = nums.size();
        int j = 0;

        priority_queue<pair<int, int>> pq;
        vector<int> dp(n);

        while(j < n) {
            dp[j] = nums[j];
            while(!pq.empty() && pq.top().second + k < j)
                pq.pop();

            if(!pq.empty())
                dp[j] = max(dp[j], dp[j] + pq.top().first);

            pq.push({dp[j], j});
            j++;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
