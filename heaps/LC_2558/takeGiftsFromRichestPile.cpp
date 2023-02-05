class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pile(gifts.begin(), gifts.end());
        long long result = 0;
        
        for(int i = 0; i < k; i++) {
            int top = sqrt(pile.top());
            pile.pop();
            
            pile.push(top);
        }
        
        while(!pile.empty()) {
            result += pile.top();
            pile.pop();
        }
        
        return result;
    }
};