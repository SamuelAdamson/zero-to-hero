class MyStack {
private:
    queue<int> q;

public:
    MyStack() { }
    
    void push(int x) {
        unsigned sz = q.size();
        q.push(x);

        for(unsigned i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
