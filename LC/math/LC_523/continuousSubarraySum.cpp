class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Modular arithmetic behavior
        // Iterate through the vector, and keep a running sum of values
        //  If we encounter the same running sum mod k more than once,
        //  then we know that in between those values there is a subarray
        //  which is a multiple of k
        unordered_set<int> modSums;
        int sum = 0, prev = 0, modSum;
        
        for(int num : nums) {
            sum += num;
            modSum = (k != 0) ? sum % k : sum;
            
            if(modSums.find(modSum) != modSums.end()) return true;
            modSums.insert(prev);
            prev = modSum;
        }
        
        return false;
    }
};