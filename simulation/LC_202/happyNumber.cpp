class Solution {
public:
    bool isHappy(int n) {
        int sum;
        unordered_set<int> visited;
        
        while(n != 1 && visited.find(n) == visited.end()) {
            sum = 0;
            visited.insert(n);
            
            while(n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        
        return n == 1;
    }
};