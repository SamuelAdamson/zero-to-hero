class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        string s = "";
        
        for(int i = 0; i < n; i++) {
            if(path[i] == '/' && (s.empty() || s.back() != '/')) s.push_back('/');
            else if(path[i] == '.' && s.back() == '/') {
                int count = 0;
                while(i < n && path[i] == '.') count++, i++;
                
                if(count <= 2 && (i >= n || (i < n && path[i] == '/'))) {
                    if(count == 2 && s.length() > 1) {
                        s.pop_back();
                        while(s.back() != '/') s.pop_back();   
                    }
                    count = 0;
                }
                
                for(int j = 0; j < count; j++) s.push_back('.');
                i--;
            }
            else if(path[i] != '/') s.push_back(path[i]);
        }
        
        if(s.length() > 1 && s.back() == '/') s.pop_back();
        return s;
    }
};