class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        int sum = 0, i;
        
        vector<int> taskFreq (26);
        priority_queue<int> pq;
        stack<int> s;
        
        for(char task : tasks) taskFreq[task-'A']++;
        for(int i : taskFreq) if(i != 0) pq.push(i);
        
        while(!pq.empty()) {
            i = 0;
            while(i <= n && !pq.empty()) {
                if(pq.top() - 1 > 0) s.push(pq.top() - 1);
                pq.pop();
                i++, sum++;
            }
            if(i <= n && !s.empty()) sum += n - i + 1;
            
            while(!s.empty()) {
                pq.push(s.top());
                s.pop();
            }
        }
        
        return sum;
    }
};