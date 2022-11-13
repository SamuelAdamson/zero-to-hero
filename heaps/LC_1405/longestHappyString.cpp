class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        
        int repeat = 0;
        char curr = ' ';
        string result = "";
        
        while(pq.top().first > 0) {
            pair<int, char> top = pq.top();
            pq.pop();
            
            if(repeat < 2 || top.second != curr) {
                result.push_back(top.second);
                top.first--;
                
                if(curr == top.second) repeat++;
                else repeat = 1, curr = top.second;
                
                pq.push(top);
            }
            else {
                if(pq.top().first > 0) {
                    pair<int, char> nextTop = pq.top();
                    pq.pop();
                    
                    result.push_back(nextTop.second);
                    nextTop.first--;                    
                    
                    repeat = 1;
                    curr = nextTop.second;
                    
                    pq.push(nextTop);
                    pq.push(top);
                }
            }
        }
        
        return result;
    }
};