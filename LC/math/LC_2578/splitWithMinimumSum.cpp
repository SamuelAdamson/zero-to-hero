class Solution {
public:
    int splitNum(int num) {
        vector<int> d(10);
        while(num > 0) {
            d[num % 10]++;
            num /= 10;
        }
        
        string num1 = "0", num2 = "0";
        bool curr = false; // false -> num1, true -> num2
        
        for(int i = 1; i < 10;) {
            if(!d[i]) i++;
            else {
                if(curr) num1.push_back(i + '0');
                else num2.push_back(i + '0');
                
                curr = !curr;
                d[i]--;
            }
        }
        
        return stoi(num1) + stoi(num2);
    }
};