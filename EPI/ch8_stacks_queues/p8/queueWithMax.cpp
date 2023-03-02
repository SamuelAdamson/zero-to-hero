#include <iostream>
#include <queue>

template <typename T>
class MaxQueue {
private:
    std::queue<T> q;
    std::deque<T> d;

    // 1 2 6 4 5 2 4 4
    // q : 1 2 6 4 5 4 4  
    // d : 6 5 4 4 

public:

    MaxQueue() {  }

    void enqueue(T val) {
        q.push(val);

        while(d.size() && val > d.back()) d.pop_back();
        d.push_back(val);
    }


    T dequeue() {
        int val = q.front();
        q.pop();

        if(val == d.front()) d.pop_front();
        return val;
    }


    T max() {
        if(!d.size()) 
            throw std::underflow_error("No elements in queue!");
        
        return d.front();
    }

};


int main() {
    // Test cases
    MaxQueue<int> q;

    q.enqueue(1);
    q.enqueue(2);

    // q : 1 2
    std::cout << "Expected 1: " << q.max() << std::endl << std::endl;

    q.dequeue();
    
    // q : 2
    std::cout << "Expected 2: " << q.max() << std::endl << std::endl;

    q.enqueue(1);
    q.dequeue();

    // q : 1
    std::cout << "Expected 1: " << q.max() << std::endl << std::endl;

    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(4);

    // q : 1 2 6 5 4 4
    std::cout << "Expected 6: " <<  q.max() << std::endl;

    // q : 2 6 5 4 4
    q.dequeue();
    std::cout << "Expected 6: " <<  q.max() << std::endl;

    // q : 6 5 4 4
    q.dequeue();
    std::cout << "Expected 6: " <<  q.max() << std::endl;

    // q : 5 4 4
    q.dequeue();
    std::cout << "Expected 5: " <<  q.max() << std::endl;

    // q : 4 4
    q.dequeue();
    std::cout << "Expected 4: " <<  q.max() << std::endl;

    // q : 4
    q.dequeue();
    std::cout << "Expected 4: " <<  q.max() << std::endl;
}