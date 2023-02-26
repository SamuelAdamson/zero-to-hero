class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*  Starting at first index, can you reach end by jumping
            a maximum of nums[i] positions.
            
            Set goal as end of list, traverse list in reverse, if any 
            values can reach that goal (check that the index plus the value
            is greater than or equal to goal) then that index becomes the new goal.
            After traversal if the goal index is 0, it is reachable.
        */
        int n = nums.size(), goal = nums.size() - 1;
        
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] + i >= goal) {
                goal = i;
            }
        }
        
        return goal == 0;
    }
};