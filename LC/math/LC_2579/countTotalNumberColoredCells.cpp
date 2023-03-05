class Solution {
public:
    /*long long coloredCells(int n) {
        if(n == 1) return 1;
        
        
        long long last = 4;
        long long res = 5;
        
        while(n > 2) {
            last += 4;
            res += last;
            n--;
        }
        
        return res;
    }*/

    long long coloredCells(int n) {
        long long m = n;
        return m * m + (m - 1) * (m - 1);
    }
};