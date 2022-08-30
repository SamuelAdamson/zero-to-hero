class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*  Move zeroes in array to the end of the array. 
            
            Use two pointers, iterating through array. If any values are 
            positive, swap them to the back of the array AFTER the last 
            positive value.
        */
        int front = 0, back = 0, n = nums.size();
        
        for(front = 0; front < n; front++) {
            if(nums[front] != 0) {
                swap(nums[front], nums[back]);
                back++;
            }
            
        }
    
    }
};