class Solution {
public:
    int partitionString(string s) {
        int count = 1, l = 0, r = 1, n = s.length();
        unordered_set<char> used({s[l]});
        
        while(r < n) {
            if(used.find(s[r]) != used.end()) {
                l = r;
                count++;
                used = { s[l] };
            }
            else {
                used.insert(s[r]);
            }
            
            r++;
        }
        
        return count;
    }
};