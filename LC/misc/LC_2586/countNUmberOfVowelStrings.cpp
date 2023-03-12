class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        int res = 0;
        
        for(int i = left; i <= right; i++) {
            if(vowels.count(words[i][0]) && vowels.count(words[i][words[i].length()-1])) res++;
        }
        
        return res;
    }
};