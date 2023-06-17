class Solution {
private:
    const int MOD_VAL = 1e9 + 7;

public:
    int numTilings(int n) {
        if(n < 3) return n;
        long long l0 = 1, l1 = 2, temp, res = 5;
        
        for(int i = 4; i <= n; i++) {
            temp = res;
            res = (2 * res + l0) % MOD_VAL;

            l0 = l1;
            l1 = temp;
        }

        return res;
    }
};