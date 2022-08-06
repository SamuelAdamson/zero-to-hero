class Solution {
public:
    int fib(int n) {
        if(n == 0) {
            return 0;
        }
        else {
            int prev = 1, curr = 1, temp;
            
            for(int i = 0; i < n-2; i++) {
                temp = curr;
                curr += prev;
                prev = temp;
            }

            return curr;
        }
    }
};