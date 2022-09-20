class Solution {
public:
    bool backspaceCompare(string s, string t) {
        bool result = true;
        int m = s.length(), n = t.length(), k = 0, p = 0;
        
        /* Stack solution O(n), O(n)
        stack<char> _s, _t;
        
        for(int i = 0; i < m; i++) {
            if(s[i] == '#' && !_s.empty()) _s.pop();
            else if(s[i] != '#') _s.push(s[i]);
        }
        
        for(int i = 0; i < n; i++) {
            if(t[i] == '#' && !_t.empty()) _t.pop();
            else if(t[i] != '#') _t.push(t[i]);
        }        
        
        if(_s.size() != _t.size()) result = false;
        while(result && !_s.empty()) {
            if(_s.top() != _t.top()) result = false;
            _s.pop();
            _t.pop();
        } */
        
        for(int i = 0; i < m; i++) {
            if(s[i] == '#') k = max(0, k-1);
            else {
                s[k] = s[i];
                k++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(t[i] == '#') p = max(0, p-1);
            else {
                t[p] = t[i];
                p++;
            }
        }
        
        if(k != p) result = false;
        for(int i = 0; i < k && result; i++) {
            if(s[i] != t[i]) result = false;
        }
        
        return result;
    }
};