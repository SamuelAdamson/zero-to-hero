#include <iostream>
#include <vector>

/**
 * @brief Given an integer encoded as an array of integers 
 *  where each element is a single digit, increment the 
 *  encoded integer.
 * @param v 
 */
void increment(std::vector<int> &v) {
    int end;
    for(end = v.size()-1; end >= 0 && v[end] == 9; end--) v[end] = 0;
    
    if(end >= 0) v[end]++;
    else {
        v[0] = 1;
        v.push_back(0);
    }
}

int main() {
    // Test cases
    std::vector<int> t1 = {1,2,9};
    std::vector<int> t2 = {4,2,3,0};
    std::vector<int> t3 = {9,9,9,9,9};

    increment(t1);
    increment(t2);
    increment(t3);

    for(int i = 0; i < t1.size(); i++) std::cout << t1[i];
    std::cout << std::endl;

    for(int i = 0; i < t2.size(); i++) std::cout << t2[i];
    std::cout << std::endl;

    for(int i = 0; i < t3.size(); i++) std::cout << t3[i];
    std::cout << std::endl;
}