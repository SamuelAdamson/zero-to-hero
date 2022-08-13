class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        /*  Get the maximum length of a subarray where the product
            is positive. Note that 0 product subarrays are not 
            considered positive.
            
            Iterate through input array, keep track of current running
            positive subarray length and negative subarray length. If 
            we encounter a negative number, we essentialy swap the values.
        */
        int pos = nums[0] > 0, neg = nums[0] < 0, temp;
        int maxLen = pos;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > 0) {
                pos++;
                neg = (neg > 0) ? neg + 1 : 0;
            }
            else if(nums[i] < 0) {
                temp = pos;
                pos = (neg > 0) ? neg + 1 : 0;
                neg = temp + 1;
            }
            else {
                pos = neg = 0;
            }
            
            maxLen = max(pos, maxLen);
        }
        
        return maxLen;
    }
};