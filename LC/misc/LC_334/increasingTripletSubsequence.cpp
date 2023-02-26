class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int start = INT_MAX, mid = INT_MAX;
        
        for(int i : nums) {
            if(i <= start) start = i;
            else if(i <= mid) mid = i;
            else return true;
        }
        
        return false;
    }
};