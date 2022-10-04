class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        int i = 0, n = strs.size(); 
        char curr;
        
        while(i < strs[0].length()) {
            curr = strs[0][i];

            for(int j = 1; j < n; j++) {
                if(i >= strs[j].length() || strs[j][i] != curr) return lcp; 
            }   
            
            lcp.push_back(curr);
            i++;
        }
        
        return lcp;
    }
};