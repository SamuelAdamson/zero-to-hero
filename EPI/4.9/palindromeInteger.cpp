#include <iostream>

/**
 * @brief Determine whether a given integer is a palindrome.
 *  Note that negative integers are not considered palindromic.
 * @param n 
 * @return true
 * @return false 
 */
bool isPalindromeInt(int n) {
    if(n < 0) return false;
    int reverse = 0, og = n;

    while(n) {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }

    return og == reverse;
}

int main() {
    // Test cases
    int t1 = 0, t2 = 7, t3 = 3445443, t4 = 55, t5 = 34463;

    std::cout << t1 << " : " << isPalindromeInt(t1) << std::endl;
    std::cout << t2 << " : " << isPalindromeInt(t2) << std::endl;
    std::cout << t3 << " : " << isPalindromeInt(t3) << std::endl;
    std::cout << t4 << " : " << isPalindromeInt(t4) << std::endl;
    std::cout << t5 << " : " << isPalindromeInt(t5) << std::endl;
}