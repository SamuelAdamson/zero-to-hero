class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> m(62); 
        string result = "";
        
        for(int i = 0; i < 26; i++) {
            if(i < 10) m[i].second = i + '0';
            m[i + 10].second = i + 'A';
            m[i + 36].second = i + 'a';
        }
        
        for(char c : s) {
            if(c <= '9') m[c - '0'].first++;
            else if(c <= 'Z') m[c - 'A' + 10].first++;
            else m[c - 'a' + 36].first++;
        }
        
        sort(m.begin(), m.end());
        for(int i = 61; i >= 0; i--) {
            while(m[i].first > 0) {
                result.push_back(m[i].second);
                m[i].first--;
            }
        }
        
        return result;
    }
};