class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<pair<int,int>> s ({{temperatures[0], 0}});

        for(int i = 1; i < n; i++) {
            while(!s.empty() && s.top().first < temperatures[i]) {
                result[s.top().second] = i - s.top().second;
                s.pop();
            }

            s.push({temperatures[i], i});
        }

        while(!s.empty()) {
            result[s.top().second] = 0;
            s.pop();
        }

        return result;
    }
};