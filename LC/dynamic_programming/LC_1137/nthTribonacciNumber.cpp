class Solution {
public:
    int tribonacci(int n) {
        /* Tribonacci Sequence
            - T_0 = 0, T_1 = 1, T_2 = 1
            - T_(n+3) = T_n + T_(n+1) + T_(n+2) for n >= 0
        
            Essentially the same approach as fibonacci sequence, store two
            previous values and current value. Sum values as we iterate.
        */
        
        if(n < 2) { // Base case
            return n; 
        }
        else {
            int twoPrev = 0, prev = 1, curr = 1;
            int temp;
            
            for(int i = 0; i < n-2; i++) {
                temp = curr;
                curr += prev + twoPrev;
                
                twoPrev = prev;
                prev = temp;
            }
            
            return curr;
        }
    }
};