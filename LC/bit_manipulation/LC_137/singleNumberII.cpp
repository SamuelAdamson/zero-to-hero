class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 0, x1 = 0, x2 = 0;

        for(int n : nums) {
            x2 ^= (x1 & n);
            x1 ^= n;
            
            mask = ~(x1 & x2);
            x1 &= mask;
            x2 &= mask;
        }

        return x1;
    }
};