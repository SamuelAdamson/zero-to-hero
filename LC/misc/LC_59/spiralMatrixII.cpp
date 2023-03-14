class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1, lr = 0, lc = 0, hr = n, hc = n, i;

        while(lr < hr && lc < hc) {
            for(i = lc; i < hc; i++) res[lr][i] = val++; 
            lr++;

            for(i = lr; i < hr; i++) res[i][hc-1] = val++;
            hc--;

            for(i = hc-1; i >= lc; i--) res[hr-1][i] = val++;
            hr--;

            for(i = hr-1; i >= lr; i--) res[i][lc] = val++;
            lc++;
        }

        return res;
    }
};