#include <iostream>
#include <string>

/**
 * @brief Replace each occurrence of 'a' with 'dd', and 
 *  remove each occurrence of 'b'.
 * @param s 
 * @param n 
 * @return std::string 
 */
void removeAndReplace(std::string& s, int n) {
    int write = 0, added = 0, i;

    for(i = 0; i < s.size(); i++) {
        if(s[i] == 'a') added++;
        if(s[i] != 'b') s[write++] = s[i];
    }

    write += added;
    for(i = write-added; i >= 0; i--) {
        if(s[i] == 'a') {
            s[write--] = 'd';
            s[write--] = 'd';
        }
        else {
            s[write--] = s[i];
        }
    }
}

int main() {
    // Test cases
    std::pair<std::string, int> t1 = {"abac_", 4};
    std::pair<std::string, int> t2 = {"acaa___", 4};

    removeAndReplace(t1.first, t1.second);
    std::cout << t1.first << std::endl;

    removeAndReplace(t2.first, t2.second);
    std::cout << t2.first << std::endl;
}