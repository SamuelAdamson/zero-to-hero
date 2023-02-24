#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>


bool wellFormed(const std::string &s) {
    std::stack<char> st;
    std::unordered_map<char, char> closeMap = {
        {'}', '{'},
        {']', '['},
        {')', '('},
    };

    for(char c : s) {
        if(closeMap.count(c)) {
            if(st.empty() || closeMap[c] != st.top()) return false;
            st.pop();
        }
        else st.push(c);
    }

    return st.empty();
}


int main() {
    // Test cases
    std::string t1 = "()()[]{}{{[()]}}";
    std::string t2 = "{(})";
    std::string t3 = "[[[{]}]]";
    std::string t4 = "(";
    std::string t5 =  "[[]{";

    std::cout << wellFormed(t1) << std::endl;
    std::cout << wellFormed(t2) << std::endl;
    std::cout << wellFormed(t3) << std::endl;
    std::cout << wellFormed(t4) << std::endl;
    std::cout << wellFormed(t5) << std::endl;
}