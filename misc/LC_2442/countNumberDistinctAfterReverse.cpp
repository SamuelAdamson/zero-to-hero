class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> vals;
        
        for(int num : nums) vals.insert(num);
        int count = vals.size();
        
        for(int num : nums) {
            if(num > 9) {
                string s = "";
                while(num > 0) {
                    s.push_back((num % 10) + '0');
                    num /= 10;
                }
                
                int newNum = stoi(s);
                if(vals.find(newNum) == vals.end()) {
                    count++;
                    vals.insert(newNum);
                }
            }
        }
        
        return count;
    }
};