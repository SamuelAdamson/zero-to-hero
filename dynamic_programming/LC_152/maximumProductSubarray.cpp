class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*  In the event of a double negatives, the minimum value
            minimum value may become the largest.
        
            So generally, we want to keep track of the smallest
            AND largest products at each step. This way we can 
            call upon the smallest value if we encounter a negative.
        */
        int maxProduct = nums[0];
        int currMin = 1, currMax = 1, prevMax;
        
        for(int num : nums) {
            prevMax = currMax;
            currMax = max(num, currMax * num);
            currMax = max(currMax, currMin * num);
            
            currMin = min(num, currMin * num);
            currMin = min(currMin, prevMax * num);
            
            maxProduct = max(currMax, maxProduct);
        }
        
        return maxProduct;
    }
};