class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        int nDiff, diff = arr[1] - arr[0], best, l, r = 2;
        bool nSign, sign;
        
        if(diff == 0) l = best = 1;
        else l = 0, best = 2;

        while(r < arr.size()) {
            nDiff = arr[r] - arr[r-1];

            if(nDiff == 0) l = r;
            else if(diff != 0) {
                sign = diff > 0;
                nSign = nDiff > 0;
                
                if(sign == nSign) l = r-1;
            }

            best = max(best, r - l + 1);
            diff = nDiff, r++;
        }

        return best;
    }
};