class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int i, smol = 1e9, best = 1e9, top;
        priority_queue<int> pq;

        for(int n : nums) {
            if(n & 1) n *= 2;
            smol = min(smol, n);
            pq.push(n);
        }
        
        while(!(pq.top() & 1)) {
            top = pq.top();

            best = min(best, top-smol);
            top /= 2;

            smol = min(smol, top);
            pq.push(top);
            pq.pop();
        }

        best = min(best, pq.top()-smol);
        return best;
    }
};