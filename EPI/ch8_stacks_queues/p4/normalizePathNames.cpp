#include <iostream>
#include <string>
#include <stack>

std::string shortestPathName(const std::string &path) {
    int n = path.size(), i;
    std::string s, prepend;
    
    // cases at each interval
    // {directory/file name}
    // . (current directory)
    // / (current directory)
    // .. (previous directory)

    // absolute path may not go up from "/"
    // relative path may start with infininte "../"

    for(i = 0; i < n; i++) {
        if(isalnum(path[i])) s.push_back(path[i]);
        else if(path[i] == '/' && (s.empty() || s.back() != '/')) s.push_back('/');
        else if(path[i] == '.' && i < n-1 && path[i+1] == '.') {
            if(s.empty()) {
                prepend += "../";
            }
            else if(s.size() > 1) {
                s.pop_back();
                while(s.size() && isalnum(s.back())) s.pop_back();
            }

            i += 2; // advance past the '../'
        }
    }

    s = prepend + s;
    if(s.size() > 1 && s.back() == '/') s.pop_back();

    return s;
}

int main() {
    // Test cases
    std::string t1 = "/usr/lib/../bin/gcc";
    std::string t2 = "scripts//./../scripts/awkscripts/././";
    std::string t3 = "/../../../../../";
    std::string t4 = "../../../../folder1/folder2/..";
    std::string t5 = "../piano/trumpet/./../saxophone././/./../";
    std::string t6 = "../../../../";

    std::cout << shortestPathName(t1) << std::endl;
    std::cout << shortestPathName(t2) << std::endl;
    std::cout << shortestPathName(t3) << std::endl;
    std::cout << shortestPathName(t4) << std::endl;
    std::cout << shortestPathName(t5) << std::endl;
    std::cout << shortestPathName(t6) << std::endl;
}