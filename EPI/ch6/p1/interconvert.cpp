#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Reimplement of stoi.
 * @param s 
 * @return int 
 */
int strToInt(const std::string& s) {
    bool negative = s[0] == '-';
    int n = 0, i;

    for(i = negative ? 1 : 0; i < s.size(); i++) {
        n *= 10;
        n += (s[i] - '0');
    }

    return negative ? n * -1 : n;
}

/**
 * @brief Convert integer to string representation.
 * @param n 
 * @return std::string 
 */
std::string intToStr(int n) {
    bool negative = n < 0;
    std::string s = negative ? "-" : "";
    n = negative ? n * -1 : n;

    while(n) {
        s.push_back(n % 10 + '0');
        n /= 10;
    }

    int l = negative ? 1 : 0, r = s.size()-1;
    while(l < r) std::swap(s[l++], s[r--]);

    return s;
}


int main() {
    // Test cases
    std::string t1 = "4123";
    std::string t2 = "10009008";
    std::string t3 = "-134";

    int t4 = 928162001;
    int t5 = 9000;
    int t6 = -8362001;

    std::cout << strToInt(t1) << std::endl;
    std::cout << strToInt(t2) << std::endl;
    std::cout << strToInt(t3) << std::endl;

    std::cout << intToStr(t4) << std::endl;
    std::cout << intToStr(t5) << std::endl;
    std::cout << intToStr(t6) << std::endl;
}