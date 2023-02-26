class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        vector<int>::iterator l, r;

        for(l = nums.end()-2, r = nums.end()-1; *l >= *r && l != nums.begin(); l--, r--);
        
        if(*l < *r) {
            for(r = nums.end()-1; *r <= *l; r--);
            iter_swap(l++, r);
        }

        reverse(l, nums.end());
    }
};