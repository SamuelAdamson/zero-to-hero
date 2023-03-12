class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0, i, j;
        vector<bitset<26>> w(words.size());

        for(i = 0; i < words.size(); i++) {
            for(char c : words[i])
                w[i][c-'a'] = 1;

            for(j = 0; j < i; j++) {
                if((w[i] | w[j]) == (w[i] ^ w[j]))
                    res = max(res, (int)(words[i].length() * words[j].length()));
            }
        }

        return res;
    }
};