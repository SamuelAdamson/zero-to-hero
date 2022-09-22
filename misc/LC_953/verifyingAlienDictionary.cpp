class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alphaOrder (26);
        int j, m, n;
        bool result = true;
        for(int i = 0; i < order.length(); i++) alphaOrder[order[i]-'a'] = i;
        
        for(int i = 1; i < words.size() && result; i++) {
            j = 0, m = words[i-1].length(), n = words[i].length();
            while(j < m && j < n && words[i-1][j] == words[i][j]) j++;
            
            if(j == m || j == n) result = j >= m;
            else if(alphaOrder[words[i][j] - 'a'] < alphaOrder[words[i-1][j] - 'a']) result = false;
        }
        
        return result;
    }
};