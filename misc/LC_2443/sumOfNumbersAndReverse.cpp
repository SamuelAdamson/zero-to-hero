class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 0) return true;
        if(num == 1) return false;
        
        for(int i = num / 2; i < num; i++) {
            string s = "";
            int curr = i;
            
            while(curr > 0) {
                s.push_back((curr % 10) + '0');
                curr /= 10;
            }
            
            if(i + stoi(s) == num) return true;
        }
        
        return false;
    }
};