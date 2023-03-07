class Solution {
private:
    bool powerOfTwo(int n) {
        return (n & (n-1)) == 0;   
    }
    
public:
    int minImpossibleOR(vector<int>& nums) {
        int mask = 0, res = 1;
        
        for(int n : nums)
            if(powerOfTwo(n)) mask |= n;
        
        while(res & mask) 
            res <<= 1;
        
        return res;
    }
};