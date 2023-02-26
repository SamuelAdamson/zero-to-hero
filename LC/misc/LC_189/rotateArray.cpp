class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while(l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    
    
    void rotate(vector<int>& nums, int k) {
        /*  Rotate an array right by k steps with O(1) space complexity.
            
            [ 1 2 3 4 5 6 7 ], 3 -> [ 5 6 7 1 2 3 4 ]
        */
        int n = nums.size();
        k %= n;
        
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};