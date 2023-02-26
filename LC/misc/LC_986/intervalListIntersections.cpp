class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size(), i = 0, j = 0;
        vector<vector<int>> result;
        
        while(i < m && j < n) {
            if(firstList[i][1] <= secondList[j][1]) {
                if(firstList[i][1] >= secondList[j][0]) {
                    result.push_back({max(firstList[i][0], secondList[j][0]), firstList[i][1]});
                }
                i++;
            }
            else {
                if(secondList[j][1] >= firstList[i][0]) {
                    result.push_back({max(secondList[j][0], firstList[i][0]), secondList[j][1]});
                }
                j++;
            }
        }
        
        
        return result;
    }
};