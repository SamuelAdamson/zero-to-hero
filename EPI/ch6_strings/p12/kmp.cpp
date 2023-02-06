#include <iostream>
#include <vector>
#include <string>

std::vector<int> createLPS(const std::string &s) {
    int m = s.size(), i, j;
    std::vector<int> lps(m);

    // in this LPS creation it is important to note
    //  that i is the leading pointer in our array here
    
    //  j becomes a trailer whenever we have a mismatch
    for(i = 1, j = 0; i < m;) {
        if(s[i] == s[j]) lps[i++] = ++j;
        else if(j) j = lps[j-1];
        else lps[i++] = 0;
    }

    return lps;
}

int kmp(const std::string &s, const std::string &sub) {
    int n = s.size(), m = sub.size(), i, j;
    std::vector<int> lps = createLPS(sub);

    // use i for string s
    // use j for sub string sub
    for(i = 0, j = 0; i < n;) {
        if(s[i] == sub[j]) {
            i++, j++;
            if(j == m) return i - m;
        }
        else {
            if(j > 0) j = lps[j-1];
            else i++;
        }
    }

    return -1;
}

int main() {
    // Test cases
    std::pair<std::string, std::string> t1 = {"abcdabcdabcdabcde", "abcde"};
    std::pair<std::string, std::string> t2 = {"apple", "pp"};
    std::pair<std::string, std::string> t3 = {"ababcabcabababd", "ababd"};
    std::pair<std::string, std::string> t4 = {"aabaaabaaac", "aabaaac"};

    std::cout << kmp(t1.first, t1.second) << std::endl;
    std::cout << kmp(t2.first, t2.second) << std::endl;
    std::cout << kmp(t3.first, t3.second) << std::endl;
    std::cout << kmp(t4.first, t4.second) << std::endl;
}