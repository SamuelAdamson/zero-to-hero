class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int i, j, a, b, result = 0;
        
        for(i = 0; i < nums.size()-1; i++) {
            for(j = i+1; j < nums.size(); j++) {
                if(gcd(to_string(nums[i])[0]-'0', nums[j]%10) == 1) result++;
            }
        }
        
        return result;
    }
};