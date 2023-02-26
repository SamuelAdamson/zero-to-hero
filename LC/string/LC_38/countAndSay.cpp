class Solution {
public:
    string helper(string &prev) {
        int cnt = 1, i;
        string result;

        for(i = 1; i < prev.size(); i++) {
            if(prev[i] == prev[i-1]) cnt++;
            else {
                result += to_string(cnt) + prev[i-1];
                cnt = 1;
            }
        }

        result += to_string(cnt) + prev[i-1];
        return result;
    }

    string countAndSay(int n) {
        string s = "1";

        for(n; n > 1; n--) {
            s = helper(s);
        }

        return s;
    }
};