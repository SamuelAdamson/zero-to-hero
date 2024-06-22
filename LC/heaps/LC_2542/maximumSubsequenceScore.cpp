class Solution {
private:

    static bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    }

public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        unsigned n = nums2.size(), i;
        long long best = 0, sum = 0;

        vector<pair<int, int>> nums(n);
        priority_queue<int, vector<int>, greater<int>> pq;

        for(i = 0; i < n; i++)
            nums[i] = make_pair(nums2[i], nums1[i]);

        sort(nums.begin(), nums.end(), compare);

        for(i = 0; i < k; i++) {
            sum += nums[i].second;
            pq.push(nums[i].second);
        }

        best = sum * nums[i-1].first;
        
        while(i < n) {
            if(nums[i].second > pq.top()) {
                sum -= pq.top();
                pq.pop();

                sum += nums[i].second;
                pq.push(nums[i].second);

                best = max(best, sum * nums[i].first);
            }
            
            i++;
        }

        return best;
    }
};

