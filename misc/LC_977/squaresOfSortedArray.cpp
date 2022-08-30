class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*  Squares of a sorted array. Return array of elements in 
            input array squared, keep the array sorted in O(n) time.
            
            [-4 -3 -2 -1]
            
            Iterate through list, while values are negative, pop them onto 
            stack. Once values become positive, add values based on aboslute value.
        */
        vector<int> result;
        stack<int> negatives;
        int sq;
        
        for(int num : nums) {
            sq = num * num;
            
            if(num < 0) negatives.push(sq);
            else {
                while(!negatives.empty() && negatives.top() <= sq) {
                    result.push_back(negatives.top());
                    negatives.pop();
                }
                result.push_back(sq);
            }
        }
        
        while(!negatives.empty()) result.push_back(negatives.top()), negatives.pop();
        return result;
    }
};