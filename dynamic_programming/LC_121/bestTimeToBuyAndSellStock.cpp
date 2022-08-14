class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*  Buy a stock on one day sell on another.
            Find maximum of prices[j] - prices[i] such that i < j.
            
            Iterate through array, at each step store the minimum value in the array so far.
            Also reset maximum by subtracting the current minimum from the current value.
        */
        
        int n = prices.size();
        int currMin = prices[0], maxProfit = 0;
        
        for(int i = 1; i < n; i++) {
            maxProfit = max(maxProfit, prices[i] - currMin);
            currMin = min(currMin, prices[i]);
            
        }
        
        return maxProfit;
    }
};