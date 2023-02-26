class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long s = 0, i;
        vector<int> div(word.size());
        
        for(i = 0; i < word.size(); i++) {
            s *= 10;
            s += word[i]-'0';
            s %= m;
            
            div[i] = !s;
        }
        
        return div;
    }
};