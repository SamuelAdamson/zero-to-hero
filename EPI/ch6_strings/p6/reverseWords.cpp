#include <iostream>
#include <string>

/**
 * @brief Reverse words in a string
 * @param s 
 */
void reverseWords(std::string &s) {
    int n = s.size(), i, l = 0, r = 0, m;

    for(i = 0; i < n/2; i++) std::swap(s[i], s[n-i-1]);
    
    while(r <= n) {
        if(r == n || s[r] == ' ') {
            m = l + (r-l)/2;
            for(i = l; i < m; i++) std::swap(s[i], s[l+r-i-1]);
            l = r + 1;
        }
        r++;
    }
}


int main() {
    // Test cases
    std::string t1 = "Alice likes Bob";
    std::string t2 = "Alice    likes      Bob";

    reverseWords(t1);
    std::cout << t1 << std::endl;

    reverseWords(t2);
    std::cout << t2 << std::endl;
}