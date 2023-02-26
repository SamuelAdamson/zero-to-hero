class MedianFinder {
private:
    priority_queue<int> low; // Max heap
    priority_queue<int, vector<int>, greater<int>> high; // Min heap
    
public:
    MedianFinder() {  }
    
    void addNum(int num) {
        low.push(num);
        
        // Here we could have just added larger element to the low side,
        //  so we want to balance, by adding to high heap
        high.push(low.top());
        low.pop();
        
        // However, now if the high heap has too many values, we want 
        //  drop off one and add to low side
        if(high.size() > low.size()) {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if(low.size() > high.size()) return low.top();
        return (high.top() + low.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */