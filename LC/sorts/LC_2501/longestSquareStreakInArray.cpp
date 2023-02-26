class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 1;
        
        // square value : number in sequence
        unordered_map<int, int> m;
        
        for(int num : nums) {
            int curr = m[num] + 1;
            if(num <= sqrt(INT_MAX)) m[num * num] = curr;
            
            result = max(curr, result);
        }
        
        return result > 1 ? result : -1;
    }
};