class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 1) return 1;
        if(n < 4) return n - 1;

        int l = 1, r = n / 2, m;
        long long val;

        while(l <= r) {
            m = l + ((r - l) / 2);
            val = ((long long)m * (m + 1)) / 2;

            if(n >= val)
                l = m + 1;
            else
                r = m - 1;
        }

        return r;
    }
};

