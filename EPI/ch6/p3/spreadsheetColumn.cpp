#include <iostream>
#include <string>

/**
 * @brief Get the integer corresponding to the column number represented
 *  by a string of letters (A -> 1, AA -> 27, AC -> 29)
 * @param s 
 * @return int 
 */
int getSpreadsheetColumn(std::string s) {
    int result = 0;
    
    for(char c : s) {
        result *= 26;
        result += (c - 'A' + 1);
    }

    return result;
}

int main() {
    // Test cases
    std::string t1 = "A";
    std::string t2 = "Z";
    std::string t3 = "AA";
    std::string t4 = "ZZ";
    std::string t5 = "ABCD";

    std::cout << getSpreadsheetColumn(t1) << std::endl;
    std::cout << getSpreadsheetColumn(t2) << std::endl;
    std::cout << getSpreadsheetColumn(t3) << std::endl;
    std::cout << getSpreadsheetColumn(t4) << std::endl;
    std::cout << getSpreadsheetColumn(t5) << std::endl;
}