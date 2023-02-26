class Solution {
public:
    void backtrack(int s, int k, int n, vector<int>& combination, vector<vector<int>>& result) {
        if(combination.size() == k)  {
            vector<int> copy(combination);
            result.push_back(copy);
        }
        else {
            for(int i = s; i <= n; i++) {
                combination.push_back(i);
                backtrack(i + 1, k, n, combination, result);
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        /*  Given integers n and k. Return all possible combinations 
            of numbers 1, n of size k.
            
            i.e. n = 4, k = 2
            [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
            
            On each combination, we can back track, remove the last value,
            and insert the next value in order.
        */
        vector<vector<int>> result;
        vector<int> combination;
        
        backtrack(1, k, n, combination, result);
        
        return result;
    }
};