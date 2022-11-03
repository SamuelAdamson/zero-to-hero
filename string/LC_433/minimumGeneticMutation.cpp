class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
        
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if(!bankSet.count(end)) return -1;
        
        string letters = "AGCT";
        queue<string> q({start});
        int level = 0, sz;
        string curr, front;
        
        while(!q.empty()) {
            sz = q.size();
            level++;
            
            for(int i = sz; sz > 0; sz--) {    
                curr = q.front();
                front = q.front();
                q.pop();
                
                bankSet.erase(curr);
                
                for(int j = 0; j < 8; j++) {
                    for(char letter : letters) {
                        curr[j] = letter;
                        if(curr == end) return level;
                        else if(bankSet.count(curr)) q.push(curr);
                    }
                    curr[j] = front[j];
                }
            }
        }
        
        return -1;
    }
};