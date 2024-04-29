class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int curr = 0, res = 0;

        for(int num : nums)
            curr ^= num;

        while(curr > 0 || k > 0) {
            if((k & 1) != (curr & 1)) res++;

            k >>= 1;
            curr >>= 1;
        }

        return res;
    }  
};

