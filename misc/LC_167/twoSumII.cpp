class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*  Given a sorted input array of numbers, find two 
            indices of numbers that add up to a target. Constant space complexity.
            
            Two pointer solution, maintain beginning and end of list. Shrink 
            list as we iterate.
        */
        int l = 0, r = numbers.size() - 1, sum;
        bool found = false;
        vector<int> result (2, 0);
        
        while(l < r && !found) {
            sum = numbers[l] + numbers[r];
            if(sum == target) {
                found = true;
                result[0] = l+1, result[1] = r+1;
            }
            else if(sum < target) l++;
            else r--;
        }
        
        return result;
    }
};