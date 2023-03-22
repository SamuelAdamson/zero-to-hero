class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int bags = 0, n = rocks.size(), i;
        vector<int> diff;
        
        for(i = 0; i < n; i++){
            if(capacity[i] == rocks[i]) bags++;
            else diff.push_back(capacity[i] - rocks[i]);
        }

        sort(diff.begin(), diff.end());
        for(i = 0; i < diff.size() && additionalRocks > 0; i++) {
            if(additionalRocks >= diff[i]) bags++;
            additionalRocks -= diff[i];
        }

        return bags;
    }
};