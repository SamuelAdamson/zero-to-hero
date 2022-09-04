class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> distances(26, 0);
        bool wellSpaced = true;
        
        for(int i = 0; i < s.length() && wellSpaced; i++) {
            if(distances[s[i]-'a'] > 0 && i - distances[s[i]-'a'] != distance[s[i]-'a']) wellSpaced = false;
            distances[s[i]-'a'] = i+1;
        }
        
        return wellSpaced;
    }
};