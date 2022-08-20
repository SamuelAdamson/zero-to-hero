class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*  Buy a stock on one day and sell on another, as many transactions 
            as you like, however there is a transaction fee. So there is incentive
            to conduct fewer transactions (less sells).
        
            At each step in the array, we can either buy, sell, or hold. If we sell, 
            we must also subtract the transaction fee from the profit. So, store two values for
            each day, the best of buying/holding a bought stock and the best of selling a 
            bought stock.
        */
        int n  = prices.size();
        int bought = -1 * prices[0], sold = 0;
        
        // Bought value : on this transaction, we bought a stock or held a previously bought stock
        // Sold value : on this transaction, we sold what we had previously bought
        
        for(int price: prices) {
            bought = max(bought, sold - price);
            sold = max(sold, bought + price - fee);
        }
        
        return sold;
    }
};