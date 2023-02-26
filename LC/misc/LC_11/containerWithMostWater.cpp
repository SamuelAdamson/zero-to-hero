class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, best, currMinHeight;
        
        while(l < r) {
            currMinHeight = min(height[l], height[r]);
            best = max(best, currMinHeight * (r-l));
            
            while(height[l] <= currMinHeight && l < r) l++;
            while(height[r] <= currMinHeight && l < r) r--;
        }
        
        return best;
    }
};