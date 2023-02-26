class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int marked = 0, i, j;
        sort(nums.begin(), nums.end());

        for(i = 0, j = (nums.size()+1) / 2; j < nums.size(); j++) {
            if(2*nums[i] <= nums[j]) marked += 2, i++;
        }

        return marked;
    }
};