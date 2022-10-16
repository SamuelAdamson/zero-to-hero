class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l, r, close, diff = 10e5, n = nums.size();
        
        for(int i = 0; i < n-2 && diff > 0; i++ ) {
            l = i + 1, r = n-1;
            int curr;
            
            while(l < r) {
                curr = nums[i] + nums[l] + nums[r];
                
                if(abs(curr - target) < diff) {
                    close = curr;
                    diff = abs(curr-target);
                }
                
                if(curr > target) r--;
                else l++;
            }
        }
     
        
        return close;
    }
};