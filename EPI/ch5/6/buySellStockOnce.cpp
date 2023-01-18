#include <iostream>
#include <vector>

/**
 * @brief Given a list of stock prices each day, determine maximum 
 *  profit when buying and selling a stock once.
 * @param v 
 * @return int 
 */
int buySellStockOnce(const std::vector<int> &v) {
    int bestBuy = v[0], bestProfit = 0;

    for(int price : v) {
        bestProfit = std::max(bestProfit, price - bestBuy);
        bestBuy = std::min(bestBuy, price);
    }

    return bestProfit;
}


int main() {
    // Test cases
    std::vector<int> t1 = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};

    std::cout << buySellStockOnce(t1) << std::endl;
}