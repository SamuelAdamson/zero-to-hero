class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(st.empty()) st.push_back(s[i]);
            else {
                if(s[i] == st.back()) st.pop_back();
                else st.push_back(s[i]);
            }
        }
        
        return st;
    }
};