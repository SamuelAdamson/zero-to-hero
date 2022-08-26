// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*  Find the first bad version using external function 
            isBadVersion.
            
            Here we want to use binary search. Start with a midpoint,
            if the midpoint is a bad version, then we shift left. If the midpoint is 
            a good version, we shift right. Continue doing so until the left 
            barrier is greater than the right.
        */
        int l = 1, r = n, mid = n;
        
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(isBadVersion(mid)) r = mid - 1;
            else l = mid + 1;
        }
        
        return isBadVersion(mid) ? mid : mid+1;
    }
};