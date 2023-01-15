#include <iostream>

/**
 * @brief Let weight be the number of bits which are flipped to 1.
 *      Note that 0 and the max unsigned integer will not have a valid result.
 * @return Closest unsigned integer with the same weight
 */
unsigned closestWithSameWeight(unsigned n) {
    for(unsigned i = 0; i < 31; i++) {
        if( (n & (1 << i)) != (n & (2 << i)) ) {
            // swap consecutve bits that differ
            return n ^ (3 << i);
        }
    }

    throw std::invalid_argument("The input must contain differing bits.");
}

int main() {
    // Test cases
    unsigned t1 = 6, t2 = 18, t3 = 235, t4 = 0;

    std::cout << t1 << " : " << closestWithSameWeight(t1) << std::endl;
    std::cout << t2 << " : " << closestWithSameWeight(t2) << std::endl;
    std::cout << t3 << " : " << closestWithSameWeight(t3) << std::endl;
    std::cout << t4 << " : " << closestWithSameWeight(t4) << std::endl;
}