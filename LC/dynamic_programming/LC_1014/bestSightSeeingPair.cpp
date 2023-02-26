class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        /*  Looking for the maximum sum of two values minus the distance between 
            the two values. For example if we have two values at i and j where i < j, 
            we calculate values[i] + values[j] + (i - j) .
            
            This term can be re-written as values[i] + i + values[j] - j. So we iterate through
            and at each step, store the best for values[i]+i and values[j]-j. Additionally,
            at each step we check if values[i] + i + values[j] - j is maximum.
        */
        int n = values.size();
        int currMaxI = values[0] + 0, maxPair = -1;
        
        for(int k = 1; k < n; k++) {
            maxPair = max(maxPair, currMaxI + values[k]-k);
            currMaxI = max(currMaxI, values[k]+k);
        }
        
        return maxPair;
    }
};