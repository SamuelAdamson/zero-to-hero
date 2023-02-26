class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), currSum, i = 0, l, r;
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        while(i < n && nums[i] <= 0) {
            if(i < 1 || nums[i] != nums[i - 1]) {
                l = i + 1, r = n - 1;
                
                while(l < r) {
                    currSum = nums[l] + nums[r] + nums[i];
                    if(currSum > 0) r--;
                    else if(currSum < 0) l++;
                    else {
                        result.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        while(l < r && nums[l] == nums[l-1]) l++;
                    }
                }
            }
            
            i++;
        }
        
        return result;
    }
};