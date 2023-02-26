class Solution {
public:
    int trap(vector<int>& height) {
        /*  Given an elevation map (the ends of the map are open),
            compute the amount of rain water which could be trapped
            by the map.

        */
        int n = height.size(), sum = 0;
        int l = 0, r = n-1, maxL = height[l], maxR = height[r];
        
        while(l < r) {
            if(maxL < maxR) {
                l++;
                maxL = max(maxL, height[l]);
                sum += maxL - height[l];
            }
            else {
                r--;
                maxR = max(maxR, height[r]);
                sum += maxR - height[r];
            }
        }
        
        
        return sum;
    }
};