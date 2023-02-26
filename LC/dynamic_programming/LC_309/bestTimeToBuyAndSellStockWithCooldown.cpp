class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*  Buy and sell stock with as many transactions as wanted.
            However, after stock is sold, one day must be waited until
            another purchase can be made. So, you cannot sell and buy
            stock on adjacent days.
            
            On each day we can either buy, sell (if we have bought before), or cooldown.
            So, keep track of three states, held state (follows buy), sold state (follows sell),
            cooldown state (follows cooldown). At each step, the held state can change buy continuing
            to hold, or selling off from the cooldown state. The cooldown state becomes the sold state.
            The sold state can be either the result from the last sell, or selling from the held state.
        */
        
        int n = prices.size();
        if(n < 2) return 0;
        
        int held = -1 * prices[0], sold = 0, cooldown = 0;
        for(int price: prices) {
            held = max(held, cooldown - price);
            cooldown = sold;
            sold = max(sold, held + price);
        }
        
        return sold;
    }
};