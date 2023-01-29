#include <iostream>
typedef unsigned long long ull;

/**
 * @brief Given a 64-bit integer, reverse the bits
 * @return 64-Bit Integer with reversed bits
 */
ull reverseBits(ull n) {
    ull result = 0;
    
    for(int i = 0; i < 64; i++) 
        if(n & (ull(1) << i)) result |= (ull(1) << (63 - i));

    return result;
}


int main() {
    // Test cases
    ull t1 = 0x1, t2 = (ull(1) << 63), t3 = 0x03248001;

    std::cout << t1 << " : " << reverseBits(t1) << std::endl;
    std::cout << t2 << " : " << reverseBits(t2) << std::endl;
    std::cout << t3 << " : " << reverseBits(t3) << std::endl;
}