class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> m1(26), m2(26);
        unordered_map<int, int> m1_counts, m2_counts;

        for(char c : word1)
            m1[c - 'a']++;

        for(char c : word2)
            m2[c - 'a']++;

        for(int i = 0; i < 26; i++) {
            if(m1[i]) {
                if(!m2[i]) return false;
                m1_counts[m1[i]]++;
            }
            
            if(m2[i]) {
                if(!m1[i]) return false;
                m2_counts[m2[i]]++;
            }
        }

        for(const pair<int, int> &p : m1_counts) {
            if(p.second != m2_counts[p.first])
                return false;
        }

        for(const pair<int, int> &p : m2_counts) {
            if(p.second != m1_counts[p.first])
                return false;
        }

        return true;
    }
};

