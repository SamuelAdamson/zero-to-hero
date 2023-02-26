class Solution {
public:
    string makeGood(string s) {
        vector<char> chars; // Using vector as stack here
        
        for(int i = 0; i < s.length(); i++) {
            if(chars.size() && (chars.back() == s[i]+32 || chars.back() == s[i]-32)) chars.pop_back();
            else chars.push_back(s[i]);
        }
        
        string result(chars.begin(), chars.end());
        return result;
    }
};