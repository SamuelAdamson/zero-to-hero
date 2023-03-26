class Solution {
private:

    int binarySearch(int target, const vector<int> &nums, int n) {
        int l = 0, m, h = n-1;

        while(l < h) {
            m = l + (h-l)/2;

            if(nums[m] < target) l = m + 1;
            else h = m;
        }

        return l;
    }


public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size(), i, j;
        
        sort(nums.begin(), nums.end());
        vector<long long> sums(n), res(m);
        
        sums[0] = nums[0];
        for(i = 1; i < n; i++)
            sums[i] = nums[i] + sums[i-1];

        // perform a binary search for each query on nums, all elemnts below
        //  are incremented up, all elements above are decremented
        for(i = 0; i < m; i++) {
            j = binarySearch(queries[i], nums, n);
            
            if(nums[j] <= queries[i]) {
                res[i] = ((long long)(j+1) * queries[i]) - sums[j];
                res[i] += ((sums[n-1] - sums[j]) - ((long long)(n-j-1)*queries[i]));
            }
            else {
                res[i] = ((long long)j*queries[i]) + (sums[n-1] - ((long long)(n-j)*queries[i]));
                if(j > 0) res[i] -= (2 * sums[j-1]);
            }
        }

        return res;
    }
};