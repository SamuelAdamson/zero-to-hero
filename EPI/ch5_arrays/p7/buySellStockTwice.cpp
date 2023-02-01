#include <iostream>
#include <vector>

/**
 * @brief Compute maximum profit from buying and selling a stock twice.
 *  At maximum you can hold 1 share at a time.
 * @param v 
 * @return int 
 */
int buySellStockTwice(const std::vector<int> &v) {
    int n = v.size(), bestBuy = v[0], bestSell = v[n-1], bestProfit = 0;
    std::vector<int> profit(n);
    
    for(int i = 1; i < n; i++) {
        bestBuy = std::min(bestBuy, v[i]);
        profit[i-1] = std::max(profit[i-2], v[i] - bestBuy);
    }

    for(int i = n-2; i >= 0; i--) {
        bestSell = std::max(bestSell, v[i]);
        bestProfit = std::max(bestProfit, bestSell - v[i] + profit[i-1]);
    }

    return bestProfit;
}


int main() {
    // Test cases
    std::vector<int> t1 = {12, 11, 13, 9, 12, 8, 14, 13, 15};
    std::vector<int> t2 = {1, 2};

    std::cout << buySellStockTwice(t1) << std::endl;
    std::cout << buySellStockTwice(t2) << std::endl;
}