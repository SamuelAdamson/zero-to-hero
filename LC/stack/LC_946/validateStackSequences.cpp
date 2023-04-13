class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, n = pushed.size();
        stack<int> s;

        while(i < n) {
            if(pushed[i] == popped[j]) {
                while(i < n && pushed[i] == popped[j]) i++, j++;
                while(!s.empty() && s.top() == popped[j]) s.pop(), j++;
            }
            else {
                s.push(pushed[i++]);
            }
        }

        while(j < n) {
            if(popped[j] != s.top()) return false;
            s.pop(), j++;
        }

        return true;
    }
};