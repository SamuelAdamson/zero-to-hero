#include <iostream>
#include <string>


/**
 * @brief Return the nth iteration of look and say.
 * @param n 
 * @return std::string 
 */
std::string lookAndSay(int n) {
    std::string s = "1", newS;
    int cnt, i;

    while(n > 1) {
        for(i = 1, cnt = 1; i < s.size(); i++, cnt++) {
            if(s[i] != s[i-1]) {
                newS += std::to_string(cnt) + s[i-1];
                cnt = 0;
            }
        }
        newS += std::to_string(cnt) + s[i-1];

        s = newS;
        newS = "";
        n--;
    }

    return s;
}


int main() {
    // Test cases
    int t1 = 1;
    int t2 = 2;
    int t3 = 3;
    int t4 = 4;
    int t8 = 8;

    std::cout << lookAndSay(t1) << std::endl;
    std::cout << lookAndSay(t2) << std::endl;
    std::cout << lookAndSay(t3) << std::endl;
    std::cout << lookAndSay(t4) << std::endl;
    std::cout << lookAndSay(t8) << std::endl;
}