class Solution {
private:
    const int MOD_VAL = 1e9 + 7;
    
public:
    int countWays(vector<vector<int>>& ranges) {        
        sort(ranges.begin(), ranges.end(), [] (const vector<int> &v1, const vector<int> &v2) {
           return v1[0] < v2[0]; 
        });
        
        int clusters = 1;
        for(int i = 1; i < ranges.size(); i++) {
            if(ranges[i][0] > ranges[i-1][1]) clusters++;
            else ranges[i][1] = max(ranges[i][1], ranges[i-1][1]);
        }
        
        unsigned long long res = 2;
        while(clusters > 1) {
            res *= 2;
            res %= MOD_VAL;
            
            clusters--;
        }
        
        return res;
    }
};