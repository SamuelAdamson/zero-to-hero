class Solution {
public:
    int countOdds(int low, int high) {
        int odd = (low & 1) + (high & 1);
        
        if(odd) return 1 + (high-low)/2;
        return (high-low)/2;
    }
};