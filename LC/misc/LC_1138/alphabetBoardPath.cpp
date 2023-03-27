class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> chMap(26);
        for(int i = 0; i < 26; i++)
            chMap[i] = {i/5, i%5};

        int r = 0, c = 0, tr, tc; 
        string res;
        
        for(char ch : target) {
            tr = chMap[ch-'a'].first;
            tc = chMap[ch-'a'].second;

            while(r != tr || c != tc) {
                if(r < tr && (c == 0 || r < 4)) {
                    res.push_back('D');
                    r++;
                }
                else if(r > tr) {
                    res.push_back('U');
                    r--;
                }
                
                if(c < tc) {
                    res.push_back('R');
                    c++;
                }
                else if(c > tc) {
                    res.push_back('L');
                    c--;
                }
            }
            res.push_back('!');
        }

        return res;
    }
};