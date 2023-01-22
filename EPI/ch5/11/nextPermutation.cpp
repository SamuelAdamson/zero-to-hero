#include <iostream>
#include <vector>

/**
 * @brief Compute the next permutation of the input array.
 * @param a 
 * @return std::vector<int> 
 */
std::vector<int> nextPermutation(const std::vector<int>& a) {
    int n = a.size(), i, j, k;

    for(i = n - 2; i >= 0 && a[i] > a[i + 1]; i--);
    if(i <= 0) return {};

    // at this point i is the index before the longest decreasing suffix
    std::vector<int> result(a);
    for(j = n - 1; j > i && a[i] > a[j]; j--);
    std::swap(result[i], result[j]);

    for(k = i + 1; k < (n - k + i); k++) std::swap(result[k], result[n - k + i]);
    return result;
}

int main() {
    // Test cases
    std::vector<int> t1 = {1, 0, 3, 2};
    std::vector<int> t2 = {3, 2, 1, 0};

    std::vector<int> r1 = nextPermutation(t1);
    std::vector<int> r2 = nextPermutation(t2);

    for(int n : r1) std::cout << n << " ";
    std::cout << std::endl;

    for(int n : r2) std::cout << n << " ";
    std::cout << std::endl;
}