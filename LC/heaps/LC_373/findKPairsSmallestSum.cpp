class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> result;
        
        auto compare = [&nums1, &nums2] (const pair<int, int> &p1, const pair<int, int> &p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        pq.push({0, 0});
        while(k > 0 && !pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            result.push_back({nums1[p.first], nums2[p.second]});

            if(p.first < n1-1) pq.push({p.first + 1, p.second});
            if(p.first == 0 && p.second < n2-1) pq.push({p.first, p.second + 1});

            k--;
        }


        return result;
    }
};