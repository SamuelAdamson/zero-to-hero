class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i;

        for(i = 0; i < intervals.size() && intervals[i][1] < newInterval[0]; i++) 
            res.push_back(intervals[i]);

        if(i < intervals.size()) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            while(i < intervals.size() && newInterval[1] >= intervals[i][0]) i++;
            if(i) newInterval[1] = max(newInterval[1], intervals[i-1][1]);
        }

        res.push_back(newInterval);
        while(i < intervals.size()) res.push_back(intervals[i++]);

        return res;
    }
};