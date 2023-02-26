class Solution {
private:
    vector<int> createLPS(const std::string &s) {
        int m = s.size(), i, j;
        vector<int> lps(m);

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

public:
    int strStr(string s, string sub) {
        int n = s.size(), m = sub.size(), i, j;
        vector<int> lps = createLPS(sub);

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
};