class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int m = n - 1, minOps = n - 1;

        set s(nums.begin(), nums.end());
        vector<int> uniqueNums(s.begin(), s.end());

        for(int i = 0; i < uniqueNums.size(); i++) {
            auto it = upper_bound(uniqueNums.begin(), uniqueNums.end(), uniqueNums[i] + m);
            int sr = distance(uniqueNums.begin(), it);

            minOps = min(minOps, n - (sr - i));
        }

        return minOps;
    }
};
