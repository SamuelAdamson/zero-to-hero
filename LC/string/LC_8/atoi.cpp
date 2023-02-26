class Solution {
public:
    int myAtoi(string s) {
        const int UL = INT_MAX / 10;
        
        int res = 0, i, n = s.size(), digit;
        bool neg = false, overflow = false;

        for(i = 0; i < n && s[i] == ' '; i++);
        if(i < n && s[i] == '-' || s[i] == '+')
            neg = s[i++] == '-' ? true : false;

        while(i < n && isdigit(s[i]) && !overflow) {
            digit = s[i++] - '0';

            if(res > UL) overflow = true;
            else {
                res *= 10;

                if(res > INT_MAX - digit) overflow = true;
                else res += digit;
            }
        }

        if(overflow) res = neg ? INT_MIN : INT_MAX;
        else res = neg ? -1 * res : res;

        return res;
    }
};