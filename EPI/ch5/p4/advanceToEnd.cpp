#include <iostream>
#include <vector>

/**
 * @brief Each element in array denotes number of positions we can advacne forward.
 *  Determine whether it is possible to reach the end of the array from the first element.
 * @param v 
 * @return true 
 * @return false 
 */
bool advance(const std::vector<int> &v) {
    int n = v.size();
    int lastReachable = n - 1;

    for(int i = n-2; i >= 0; i--) {
        if(i + v[i] >= lastReachable) lastReachable = i;
    }

    return lastReachable == 0;
}

int main() {
    // Test cases
    std::vector<int> t1 = {3, 3, 1, 0, 2, 0, 1};
    std::vector<int> t2 = {3, 2, 0, 0, 2, 0, 1};

    std::cout << "Test 1: " << advance(t1) << std::endl;
    std::cout << "Test 2: " << advance(t2) << std::endl;
}