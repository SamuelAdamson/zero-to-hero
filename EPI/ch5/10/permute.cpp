#include <iostream>
#include <vector>


void dfs(
    std::vector<char>& a, 
    const std::vector<int>& p, 
    std::vector<bool>& visited,
    int i, char c
) {
    if(!visited[i]) {
        visited[i] = true;
        dfs(a, p, visited, p[i], a[i]);
    }

    a[i] = c;
}

/**
 * @brief Apply a permutation to an array
 * @param a
 * @param p 
 */
void permute(std::vector<char>& a, const std::vector<int>& p) {  
    int n = a.size();
    std::vector<bool> visited(n);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs(a, p, visited, p[i], a[i]);
    }

}

void permute2(std::vector<char>& a, std::vector<int>& p) {
    int n = a.size();
    
    for(int i = 0; i < n; i++) {
        while(p[i] != i) {
            std::swap(a[i], a[p[i]]);
            std::swap(p[i], p[p[i]]);
        }
    }
}

int main() {
    // Test cases
    std::pair<std::vector<char>, std::vector<int>> t1 = {{'a', 'b', 'c', 'd'}, {2, 0, 1, 3}};
    std::pair<std::vector<char>, std::vector<int>> t2 = {{'a', 'b', 'c', 'd', 'e', 'f'}, {2, 0, 1, 4, 3, 5}};

    // permute(t1.first, t1.second);
    // permute(t2.first, t2.second);

    permute2(t1.first, t1.second);
    permute2(t2.first, t2.second);

    for(char c : t1.first) std::cout << c << " ";
    std::cout << std::endl;

    for(char c : t2.first) std::cout << c << " ";
    std::cout << std::endl;
}