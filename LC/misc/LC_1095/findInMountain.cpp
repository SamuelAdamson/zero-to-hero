/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int binarySearch_peak(MountainArray &ma) {
        int l = 0, h = ma.length()-1, m;
        int mid, midLow, midHigh;

        while(l <= h) {
            m = l + (h-l)/2;

            if(m == 0) {
                m++;
                break;
            }

            mid = ma.get(m);
            midLow = ma.get(m-1);
            midHigh = ma.get(m+1);

            if(midLow < mid && midHigh < mid)
                break;
            else if(midLow > mid)
                h = m - 1;
            else
                l = m + 1;
        }

        return m;
    }
    
    int binarySearch_asc(MountainArray &ma, int h, int target) {
        int l = 0, m;

        while(l < h) {
            m = l + (h-l)/2;

            if(ma.get(m) < target)
                l = m + 1;
            else 
                h = m;
        }

        return l;
    }

    int binarySearch_des(MountainArray &ma, int l, int target) {
        int h = ma.length()-1, m;

        while(l < h) {
            m = l + (h-l)/2;

            if(ma.get(m) > target)
                l = m + 1;
            else
                h = m;
        }

        return l;
    }

public:
    int findInMountainArray(int target, MountainArray &ma) {
        int sr_peak = binarySearch_peak(ma); // find peak

        // search ascending array
        int sr_asc = binarySearch_asc(ma, sr_peak, target);
        if(ma.get(sr_asc) == target) return sr_asc;

        // search descending array
        int sr_des = binarySearch_des(ma, sr_peak + 1, target);
        if(ma.get(sr_des) == target) return sr_des;

        return -1;
    }
};
