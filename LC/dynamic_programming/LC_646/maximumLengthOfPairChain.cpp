class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int currMax = pairs[0][1], best = 1;

        for(unsigned i = 1; i < pairs.size(); i++) {
            if(pairs[i][0] > currMax) {
                best++;
                currMax = pairs[i][1];
            }
            else if(pairs[i][1] < currMax) {
                currMax = pairs[i][1];
            }
        }

        return best;
    }
};
