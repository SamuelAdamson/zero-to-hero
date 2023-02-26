class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*  List of stock prices, where price on ith day is prices[i]. 
            What is the maximum profit that can be achieved if you can
            buy and sell the stock multiple times.
            
            Iterate through the list, at each step store the current minimum 
            and the current maximum. If we encounter a price that is lower than the 
            current maximum, sell the stock at the maximum price. and reset minimum/maximum.
        */
        int maxProfit = 0, currMaxPrice = prices[0], currMinPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < currMaxPrice) {
                maxProfit += currMaxPrice - currMinPrice;
                currMinPrice = currMaxPrice = prices[i];
            }
            else {
                currMaxPrice = prices[i];
            }
        }
        
        return max(maxProfit, maxProfit + (currMaxPrice - currMinPrice));
    }
};