class Node {
public:
    int val;
    Node *next;
    Node *prev;
    
    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class MyCircularDeque {
private:
    Node *front, *last;
    int size, maxSize;
    
public:
    MyCircularDeque(int k) {
        front = NULL;
        last = NULL;
        maxSize = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if(size >= maxSize) return false;
        Node *newFront = new Node(value);
        
        if(front) {
            newFront->next = front->next;
            newFront->prev = front;
            front->next = newFront;
        }
        front = newFront;
        
        if(!last) last = front, last->next = front;
        last->prev = front;  
        
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size >= maxSize) return false;
        Node *newLast = new Node(value);
        
        if(last) {
            newLast->prev = last->prev;
            newLast->next = last;
            last->prev = newLast;
        }
        last = newLast;
        
        if(!front) front = last, front->prev = last;
        front->next = last;
        
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(!size) return false;
        
        Node *toRemove = front;
        front = front->prev;
        last->prev = front;
        
        delete toRemove;
        size--;
        
        if(!size) last = front = NULL;
        return true;
    }
    
    bool deleteLast() {
        if(!size) return false;
        
        Node *toRemove = last;        
        last = last->next;
        front->next = last;
        
        delete toRemove;
        size--;
        
        if(!size) last = front = NULL;
        return true;
    }
    
    int getFront() {
        if(!size) return -1;
        return front->val;
    }
    
    int getRear() {
        if(!size) return -1;
        return last->val;
    }
    
    bool isEmpty() {
        return size <= 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */