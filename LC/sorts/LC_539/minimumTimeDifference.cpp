class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        timePoints.push_back(
            to_string(stoi(timePoints[0].substr(0, 2)) + 24) + timePoints[0].substr(2, 3)
        );

        int i, j, diff = INT_MAX, t;
        int last = (stoi(timePoints[0].substr(0,2)) * 60) + stoi(timePoints[0].substr(3,2));
        for(j = 1; j < timePoints.size(); j++) {
            t = (stoi(timePoints[j].substr(0,2)) * 60) + stoi(timePoints[j].substr(3,2));
            diff = min(diff, t - last);

            last = t;
        }

        return diff;
    }
};