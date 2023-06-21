class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), denom = 2*k+1, i, j, m;
        long long sum = 0;
        vector<int> result(n, -1);

        for(i = 0, j = 0, m = k; j < n; j++) {
            sum += nums[j];

            if(j >= 2 * k) {
                result[m++] = sum / denom;
                sum -= nums[i++];
            }
        }
        
        return result;
    }
};