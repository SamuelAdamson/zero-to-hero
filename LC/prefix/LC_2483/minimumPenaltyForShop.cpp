class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), i, penalty = 0;

        for(i = n-1; i >= 0; i--)
            if(customers[i] == 'Y') penalty++;

        int idx = 0, best = penalty;
        for(i = 1; i <= n; i++) {
            penalty = (customers[i-1] == 'N') ? penalty+1 : penalty-1;
            if(penalty < best) {
                idx = i;
                best = penalty;
            }
        }

        return idx;
    }
};
