class Solution {
public:
    int climbStairs(int n) {
        /* Stair case with n stairs, you can climb to the top by
           taking one or two steps, how many unique ways are there
           to climb to the top.
           
           3 : 3 -> (1,1,1) (1,2) (2,1)
           4 : 5 -> (1,1,1,1) (2,2) (2,1,1) (1,2,1) (1,1,2)
           5 : 8 -> (1,1,1,1,1) (2,2,1) (2,1,2) (1,2,2) (1,1,1,2) (1,1,2,1) (1,2,1,1) (2,1,1,1)
           
           Basically, it's Fibonacci
        */
        if (n < 4) {
            return n;
        }
        else {
            int prev = 3, curr = 5, temp;
            for(int i = 0; i < n - 4; i++) {
                temp = curr;
                curr += prev;
                prev = temp;
            }
            
            return curr;
        }
    }
};