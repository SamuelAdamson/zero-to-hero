class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors.push_back('0');
        int cost = 0, currMax = 0, currTotal = 0;
        bool repeat = false;
        
        for(int i = 1; i < colors.size(); i++) {
            if(colors[i] == colors[i-1]) {
                if(repeat) {
                    currMax = max(neededTime[i], currMax);
                    currTotal += neededTime[i];
                }
                else {
                    repeat = true;
                    currTotal += neededTime[i] + neededTime[i-1];
                    currMax = max(neededTime[i], neededTime[i-1]);
                }
            }
            else if(repeat) {
                repeat = false;
                cost += currTotal - currMax;
                currMax = currTotal = 0;
            }
        }
        
        return cost;
    }
};