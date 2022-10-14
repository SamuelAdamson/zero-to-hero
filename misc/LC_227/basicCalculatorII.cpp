class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> operands;
        vector<char> operators;
        
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                if(s[i] >= '0' && s[i] <= '9') {
                    string curr = "";
                    int currNum, j = i;
                    char currOp = (operators.size() > 0) ? operators.back() : ' ';
                    
                    while(j < n && s[j] >= '0' && s[j] <= '9') {
                        curr.push_back(s[j]);
                        j++;
                    }
                    i = j-1;
                    currNum = stoi(curr);
                    
                    if(currOp == '*' || currOp == '/') {
                        if(currOp == '*') currNum *= operands.back();
                        else if(currOp == '/') currNum = operands.back() / currNum;
                        
                        operators.pop_back();
                        operands.pop_back();
                    }
                    
                    operands.push_back(currNum);
                }
                else operators.push_back(s[i]);
            }
        }
        
        int i = 1, j = 0;
        while(j < operators.size()) {
            if(operators[j] == '+') operands[0] += operands[i];
            else operands[0] -= operands[i];
            
            i++, j++;
        }
        
        return operands[0];
    }
};