class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [] (const vector<int> &v1, const vector<int> &v2) {
                return v1[0] < v2[0];
            });

        vector<vector<int>> res;
        vector<int> curr(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= curr[1]) curr[1] = max(curr[1], intervals[i][1]);
            else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }

        res.push_back(curr);
        return res;
    }
};