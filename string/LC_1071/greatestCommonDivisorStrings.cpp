class Solution {
public:
    // bool isGcd(string sub, string s) {
    //     int m = sub.size(), n = s.size();
    //     if(n % m != 0) return false;

    //     for(int i = m; i <= n - m; i += m) {
    //         for(int j = i; j < i + m; j++) {
    //             if(sub[j-i] != s[j]) return false;
    //         }
    //     }

    //     return true;
    // }

    // string gcdOfStrings(string str1, string str2) {
    //     int m = str1.size(), n = str2.size(), i;
    //     string s = "";

    //     for(i = 0; i < m && i < n && str1[i] == str2[i]; i++) s.push_back(str1[i]);
    //     while(s.size() && (!isGcd(s, str1) || !isGcd(s, str2))) s.pop_back(); 

    //     return s;
    // }

    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};