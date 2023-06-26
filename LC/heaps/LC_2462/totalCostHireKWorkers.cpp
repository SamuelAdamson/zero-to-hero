class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size(), l, r;
        long long cost = 0;

        priority_queue<int, vector<int>, greater<int>> lh, rh;
        
        for(l = 0; l < candidates; l++) lh.push(costs[l]);
        for(r = n-1; r >= l && r >= (n - candidates); r--) rh.push(costs[r]);

        while(k > 0) {
            if(lh.empty() || rh.empty()) {
                if(lh.empty()) {
                    cost += rh.top();
                    rh.pop();
                }
                else {
                    cost += lh.top();
                    lh.pop();
                }
            }
            else {
                if(lh.top() <= rh.top()) {
                    cost += lh.top();
                    lh.pop();
                    
                    if(l <= r) lh.push(costs[l++]);
                }
                else {
                    cost += rh.top();
                    rh.pop();

                    if(l <= r) rh.push(costs[r--]);
                }
            }


            k--;
        }

        return cost;
    }
};