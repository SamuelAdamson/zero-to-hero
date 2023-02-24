class Solution {
const int UL = INT_MAX / 10;

public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;

        bool neg = false;
        int result = 0, digit;

        if(x < 0) {
            neg = true;
            x *= -1;
        }

        while(x) {
            digit = x % 10;
            
            if(result > UL) return 0;
            result *= 10;

            if(INT_MAX - result < digit) return 0;
            result += digit;
            
            x /= 10;
        }

        return neg ? result * -1 : result;
    }
};