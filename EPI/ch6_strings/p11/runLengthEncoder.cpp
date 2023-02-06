#include <iostream>
#include <string>


class RunLengthEncoder {
    public:
        RunLengthEncoder() {  }

        std::string encode(const std::string &s) {
            int cnt = 1, i;
            std::string result;

            for(i = 1; i < s.size(); i++) {
                if(s[i] == s[i-1]) cnt++;
                else {
                    result += std::to_string(cnt) + s[i-1];
                    cnt = 1;
                }
            }

            result += std::to_string(cnt) + s[i-1];
            return result;
        }

        std::string decode(const std::string &s) {
            int i, cnt;
            std::string result;

            for(i = 0; i < s.size()-1; i += 2) {
                for(cnt = s[i]-'0'; cnt > 0; cnt--) {
                    result.push_back(s[i+1]);
                }
            }

            return result;
        }
};


int main() {
    // Test cases
    std::string t1 = "eeeffffeeaddss";
    std::string t2 = "abcdeeeefffg";

    std::string t3 = "2a5s1a1r";
    std::string t4 = "2d4f5g";

    RunLengthEncoder rle;

    std::cout << rle.encode(t1) << std::endl;
    std::cout << rle.encode(t2) << std::endl;

    std::cout << rle.decode(t3) << std::endl;
    std::cout << rle.decode(t4) << std::endl;
}