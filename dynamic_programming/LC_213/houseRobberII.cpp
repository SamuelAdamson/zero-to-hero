class Solution {
public:
    int robHelper(int s, int e, vector<int> nums) {
        int rob1 = 0, rob2 = 0, best;
        
        for(int i = s; i < e; i++) {
            best = max(rob1, rob2 + nums[i]);
            rob2 = rob1;
            rob1 = best;
        }
        
        return rob1;
    }
    
    int rob(vector<int>& nums) {
        /* Similar to House Robber 1 except, we cannot choose both the first and last
           element in our best solution.
           
           So, perform best selection excluding the first element, and excluding 
           the last element, take the best of these. One caveat, since we run twice, we
           cannot use the array as a means of storing values.
        */
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        else {
            return max(robHelper(0, n-1, nums), robHelper(1, n, nums));   
        }
    }
};