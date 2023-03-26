class Solution {
public:
    int helper(int last, int curr) {
        int high = curr-last-1, i;
        bool prime; 
        
        while(high >= 2) {
            prime = true;
            for(i = 2; i <= high/2 && prime; i++) {
                if(high % i == 0) prime = false;
            }
            
            if(prime) return curr - high;
            high--;
        }
        
        return curr;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        if(nums.size() == 1) return true;
        nums[0] = helper(0, nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = helper(nums[i-1], nums[i]);
            if(nums[i] <= nums[i-1]) return false;
        }
        
        
        return true;
    }
};