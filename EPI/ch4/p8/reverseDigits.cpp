#include <iostream>

/**
 * @brief Reverse the digits of an input integer
 * @return int
 */
int reverseDigits(int n) {
    int result = 0, digit;

    while(n) {
        result = result * 10 + (n % 10);
        n /= 10;
    }

    return result;
}

int main() {
    // Test cases
    int t1 = -314, t2 = 43, t3 = 0, t4 = 1;

    std::cout << t1 << " : " << reverseDigits(t1) << std::endl;
    std::cout << t2 << " : " << reverseDigits(t2) << std::endl;
    std::cout << t3 << " : " << reverseDigits(t3) << std::endl;
    std::cout << t4 << " : " << reverseDigits(t4) << std::endl;
}