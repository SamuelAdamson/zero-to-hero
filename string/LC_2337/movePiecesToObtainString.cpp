class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, n = start.length();
        
        while(i < n && j < n) {
            if(start[i] == '_') i++;
            else if (target[j] == '_') j++;
            else {
                if(start[i] != target[j]) return false;
                if(start[i] == 'L' && i < j) return false;
                if(start[i] == 'R' && j < i) return false;

                i++, j++;
            }
        }

        while(i < n && start[i] == '_') i++;
        while(j < n && target[j] == '_') j++;

        return i == n && j == n;
    }
};