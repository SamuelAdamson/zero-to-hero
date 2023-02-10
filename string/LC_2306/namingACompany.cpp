class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int i, j, n = ideas.size();
        long long result = 0, mutual;
        vector<unordered_set<string>> prefix(26);

        for(i = 0; i < n; i++) 
            prefix[ideas[i][0]-'a'].insert(ideas[i].substr(1));

        for(i = 0; i < 25; i++) {
            for(j = i + 1; j < 26; j++) {
                mutual = 0;

                for(auto &s : prefix[i]) {
                    if(prefix[j].count(s)) mutual++;
                }

                result += 2 * (prefix[i].size() - mutual) * (prefix[j].size() - mutual);
            }
        }

        return result;
    }
};