class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2);
        
        int mask;
        for(int i = 0; i < 11; i++) {
            mask = (1 << i);
            
            if(mask & n) {
                if(i % 2) res[1]++;
                else res[0]++;
            }
        }
        
        return res;
    }
};