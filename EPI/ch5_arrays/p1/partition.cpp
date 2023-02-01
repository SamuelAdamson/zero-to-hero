#include <iostream>
#include <vector>

/**
 * @brief Partition an input vector around the value at index i (two passes).
 * @param v 
 * @param i 
 */
void partition_v1(std::vector<int> &v, int i) {
    int p = v[i], n = v.size();

    int smaller = 0;
    for(int j = 0; j < n; j++) {
        if(v[j] < p) std::swap(v[j], v[smaller++]);
    }

    int larger = n-1;
    for(int j = 0; j < n; j++) {
        if(v[j] > p) std::swap(v[j], v[larger--]);
    }
}

/**
 * @brief Partition an input vector around the value at index i (one pass).
 * @param v 
 * @param i 
 */
void partition_v2(std::vector<int> &v, int i) {
    int p = v[i], n = v.size();
    int smaller = 0, larger = n-1, next = 0;

    while(next < larger) {
        if(v[next] < p) std::swap(v[next++], v[smaller++]);
        else if(v[next] > p) std::swap(v[next], v[larger--]);
        else next++;
    }
}

int main() {
    // Test cases
    std::pair<std::vector<int>, int> t1 = {{2, 3, 4, 3, 5, 6, 5}, 2};
    std::pair<std::vector<int>, int> t2 = {{7, 8, 2, 4, 10, -1, 2}, 3};

    // partition_v1(t1.first, t1.second);
    // partition_v1(t2.first, t2.second);

    partition_v2(t1.first, t1.second);
    partition_v2(t2.first, t2.second);

    for(int i = 0; i < t1.first.size(); i++) std::cout << t1.first[i] << " ";
    std::cout << std::endl;

    for(int i = 0; i < t2.first.size(); i++) std::cout << t2.first[i] << " ";
    std::cout << std::endl;
}