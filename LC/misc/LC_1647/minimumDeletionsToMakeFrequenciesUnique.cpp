class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26);
        for(char c : s)
            f[c-'a']++;

        int result = 0;
        unordered_set<int> freqs;
        for(int n : f) {
            if(n == 0) continue;
            while(n > 0 && freqs.find(n) != freqs.end()) {
                n--;
                result++;
            }
            freqs.insert(n);
        }

        return result;
    }
};