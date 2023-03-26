class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int res = 0;
        
        if(numOnes >= k) return k;
        res += numOnes;
        k -= numOnes;
        
        if(numZeros >= k) return res;
        k -= numZeros;
        
        res += (-1 * k);
        return res;
    }
};