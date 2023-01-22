#include <iostream>
#include <vector>
#include <random>

/**
 * @brief Return a random subset of a of size k. All subsets should have equal
 *  probability.
 * @param a 
 * @param k 
 * @return std::vector<int> 
 */
std::vector<int> randomSubset(std::vector<int> a, int k) {
    int n = a.size(), index;
    std::vector<int> result(k);

    for(int i = 0; i < k; i++) {
        index = std::rand() % (n-i) + i;
        result[i] = a[index];

        // take the value out of the running
        std::swap(a[index], a[i]);
    }

    return result;
}

int main() {
    // Test cases
    std::pair<std::vector<int>, int> t1({{1, 2, 3, 4, 5, 6, 7}, 3});
    std::pair<std::vector<int>, int> t2({{7, 6, 5, 4, 3, 2, 1}, 4});

    std::vector<int> r1 = randomSubset(t1.first, t1.second);
    std::vector<int> r2 = randomSubset(t2.first, t2.second);

    for(int n : r1) std::cout << n << " ";
    std::cout << std::endl;

    for(int n : r2) std::cout << n << " ";
    std::cout << std::endl;
}