class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        /*  Longest subarray where the bitwise and of every element 
            is equal to 0.        
            
            Take a sliding window of the array. Keep a template of bits 
            as we iterate. This template will be the result of an or 
            operation on every new element.
        */
        int maxLen = 1, l = 0, r = 1, bitTemplate = 0, toRemove, temp;
        string bitList;
        vector<int> addedBits(32, 0); 
        
        bitTemplate = bitTemplate | nums[l];
        while(r < nums.size()) {
            if((bitTemplate & nums[r]) != 0) {
                toRemove = (bitTemplate & nums[r]);
                bitList = bitset<32>(toRemove).to_string();
                for(int i = 0; i < 32; i++) {
                    if(bitList[i]-'0' == 1) {
                        l = max(l, addedBits[i] + 1);
                    }
                }
            }
            
            bitTemplate = (bitTemplate | nums[r]);
            bitList = bitset<32>(nums[r]).to_string();
            for(int i = 0; i < 32; i++) {
                if(bitList[i]-'0') addedBits[i] = r;
            }
            
            maxLen = max(r-l+1, maxLen);
            r++;
        }
        
        return maxLen;
    }
};