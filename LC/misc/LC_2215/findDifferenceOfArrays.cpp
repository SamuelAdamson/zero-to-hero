class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2);
        unordered_set<int> nums1_distinct, nums2_distinct;

        for(int num : nums1)
            nums1_distinct.insert(num);

        for(int num : nums2)
            nums2_distinct.insert(num);

        for(auto it = nums1_distinct.begin(); it != nums1_distinct.end(); ++it) {
            if(!nums2_distinct.count((int)*it))
                result[0].push_back((int)*it);
        }

        for(auto it = nums2_distinct.begin(); it != nums2_distinct.end(); ++it) {
            if(!nums1_distinct.count((int)*it))
                result[1].push_back((int)*it);
        }

        return result;
    }
};

