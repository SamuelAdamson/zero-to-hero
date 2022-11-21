class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        
        int curr = 0, result = 0;
        int sign = 1;
        
        for(char c : s) {
            if(isdigit(c)) curr = (curr * 10) + (c - '0');
            else if(c == '+') {
                result += sign * curr;
                curr = 0, sign = 1;
            }
            else if(c == '-') {
                result += sign * curr;
                curr = 0, sign = -1;
            }
            else if(c == '(') {
                st.push(result);
                st.push(sign);
                
                result = 0;
                sign = 1;
            }
            else if(c == ')') {
                result += sign * curr;
                curr = 0;
                
                result *= st.top();
                st.pop();
                
                result += st.top();
                st.pop();
            }
        }
        
        if(curr) result += sign * curr;
        return result;
    }
};