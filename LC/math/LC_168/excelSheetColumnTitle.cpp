class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        
        while(columnNumber > 0) {
            if(columnNumber % 26 == 0) {
                res.push_back('Z');
                columnNumber = (columnNumber / 26) - 1;
            }
            else {
                res.push_back('A' + (columnNumber % 26 - 1));
                columnNumber /= 26;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};