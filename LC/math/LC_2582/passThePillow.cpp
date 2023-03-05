class Solution {
public:
    int passThePillow(int n, int time) {
        int k = time % (n-1);
        
        if((time / (n-1)) % 2) return n - k;
        else return k + 1;
    }
};