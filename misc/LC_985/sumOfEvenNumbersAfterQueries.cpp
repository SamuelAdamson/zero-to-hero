class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), evenSum = 0;
        vector<int> result;
        
        for(int i = 0; i < n; i++) if(!(nums[i] & 1)) evenSum += nums[i];   
        
        for(int i = 0; i < queries.size(); i++) {
            // odd + odd = even
            // even + even = even
            // odd + even = odd
            
            int idx = queries[i][1], val = queries[i][0];
            bool numOdd = nums[idx] & 1, valOdd = val & 1;
    
            int num = nums[idx];
            nums[idx] += val;
            
            if(numOdd && valOdd) evenSum += nums[idx];
            else if(!numOdd && valOdd) evenSum -= num;
            else if(!numOdd && !valOdd) evenSum += val;
            
            result.push_back(evenSum);
        }
        
        return result;
    }
};