#include <iostream>
#include <queue>
#include <vector>
#include <functional>

struct Value {
    // value
    int val;
    
    int sequence; // index for sequence in input
    int index; // index for value in sequence
};

std::vector<int> merge(std::vector<std::vector<int>> sequences) {
    std::vector<int> res;
    std::priority_queue<Value, std::vector<Value>, std::function<bool(const Value&, const Value&)>>  pq(
        [] (const Value &v1, const Value &v2) {
            return v1.val > v2.val;
        });
    
    for(int i = 0; i < sequences.size(); i++)
        pq.push({sequences[i][0], i, 1});

    while(!pq.empty()) {
        Value v = pq.top();
        pq.pop();

        res.push_back(v.val);
        if(v.index < sequences[v.sequence].size())
            pq.push({sequences[v.sequence][v.index], v.sequence, v.index+1});
    }

    return res;
}

int main() {
    std::vector<std::vector<int>> t1 = {{0,6,28}, {0,6}, {3,5,7}};

    std::vector<int> r1 = merge(t1);

    for(int n : r1) std::cout << n << " ";
    std::cout << std::endl;
}