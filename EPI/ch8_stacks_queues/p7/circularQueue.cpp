#include <iostream>

class CircularQueue {
private:
    int cap, head, tail, n;
    int *q;

public:
    CircularQueue(unsigned capacity) {
        cap = capacity;
        tail = head = n = 0;

        q = new int [cap];
    }

    int capacity() {
        return cap;
    }

    int size() {
        return n;
    }

    void enqueue(int value) {
        if(n == cap) {
            int *temp = new int [cap * 2];
            int i, j;
            
            for(i = tail, j = 0; i < n; i++, j++) temp[j] = q[i & cap];

            delete[] q; // deallocate
            q = temp;
            
            cap *= 2;
            head = j, tail = 0;
        }

        q[head] = value;
        head = (head + 1) % cap;
        n++;
    }

    int dequeue() {
        if(!n)
            throw std::underflow_error("circular queue is empty!");
        
        int value = q[tail];
        tail = (tail + 1) % cap;
        n--;

        return value;
    }

};


int main() {
    // Test case
    CircularQueue *cq = new CircularQueue(5);

    // exception
    // int i = cq->dequeue();

    cq->enqueue(4);
    cq->enqueue(17);
    cq->enqueue(200);
    cq->enqueue(1);
    cq->enqueue(3);

    std::cout << "Size and capacity: " << std::endl;
    std::cout << cq->size() << std::endl;
    std::cout << cq->capacity() << std::endl;

    std::cout <<std::endl << "Tail: " << std::endl;
    std::cout << cq->dequeue() << std::endl;
    cq->enqueue(17);
    
    std::cout << std::endl << "Size and capacity: " << std::endl;
    std::cout << cq->size() << std::endl;
    std::cout << cq->capacity() << std::endl;

    cq->enqueue(32);
    cq->enqueue(28);

    std::cout << std::endl << "Size and capacity: " << std::endl;
    std::cout << cq->size() << std::endl;
    std::cout << cq->capacity() << std::endl;

    std::cout <<std::endl << "Tail: " << std::endl;
    std::cout << cq->dequeue() << std::endl;
}