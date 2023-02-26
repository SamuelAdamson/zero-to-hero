class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);

        // So, we initialize this to one because for example if the first
        //  coin is 1, then we will reference this first tile for our number of 
        //  combinations -- everything else in dp is initialized to 0
        dp[0] = 1;

        for(int coin : coins) {
            // Note this only runs when coin >= amount
            //  when we get to the stage where j >= 2 * our coin value
            //  we will increase the amount of combos we have
            for(int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};