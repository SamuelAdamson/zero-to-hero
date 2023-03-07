class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        
        // int res = min(nums[n-1]-nums[2], nums[n-2]-nums[1]);
        // return min(nums[n-3]-nums[0], res);
        int s1 = INT_MAX, s2 = INT_MAX, s3 = INT_MAX;
        int l1 = 0, l2 = 0, l3 = 0;

        for(int n : nums) {
            if(n < s1) s3 = s2, s2 = s1, s1 = n;
            else if(n < s2) s3 = s2, s2 = n;
            else if(n < s3) s3 = n;

            if(n > l1) l3 = l2, l2 = l1, l1 = n;
            else if(n > l2) l3 = l2, l2 = n;
            else if(n > l3) l3 = n;
        }

        int res = min(l1 - s3, l2 - s2);
        return min(res, l3 - s1);
    }
};