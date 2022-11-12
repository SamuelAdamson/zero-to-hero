class StockSpanner {
private:
    // price, span
    stack<pair<int, int>> prices;
    
public:
    StockSpanner() { 
        return;
    }
    
    int next(int price) {
        int span = 1;
        
        while(!prices.empty() && price >= prices.top().first) {
            span += prices.top().second;
            prices.pop();
        }
        
        prices.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */