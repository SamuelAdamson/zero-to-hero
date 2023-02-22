#include <iostream>
#include <string>
#include <stack>

int evaluateExpression(int x, int y, char op) {
    switch(op) {
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        default: return x/y;
    }
}

int evaluateRPN(const std::string &s) {
    std::stack<int> st;
    std::string curr;
    int result = 0, x, y, n = s.size();

    for(int i = 0; i < n; i++) {
        if(s[i] == '+' || (s[i] == '-' && (i == n-1 || s[i+1] == ',')) || s[i] == '*' || s[i] == '/') {
            y = st.top();
            st.pop();

            x = st.top();
            st.pop();

            st.push(evaluateExpression(x, y, s[i]));
            curr = "";
        }
        else if(s[i] == ',') {
            if(!curr.empty()) st.push(stoi(curr));
            curr = "";
        }
        else {
            curr.push_back(s[i]);
        }
    }

    if(!curr.empty()) st.push(stoi(curr));
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    // Test cases
    std::string t1 = "1729";
    std::string t2 = "1729,-43,-";
    std::string t3 = "1729,-43,-,3,+,155,-,987,+";

    std::cout << evaluateRPN(t1) << std::endl;
    std::cout << evaluateRPN(t2) << std::endl;
    std::cout << evaluateRPN(t3) << std::endl;
}