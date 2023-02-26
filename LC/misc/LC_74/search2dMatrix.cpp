class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary search by row
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m - 1, mid, row;
        
        while(l < h) {
            mid = l + (h - l)/2;
            
            if(matrix[mid][n-1] < target) l = mid + 1;
            else h = mid;
        }
        row = l;
        
        // Binary search by col
        l = 0, h = n - 1;
        while(l <= h) {
            mid = l + (h-l)/2;
            
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] < target) l = mid + 1;
            else h = mid - 1;
        }
        
        return false;
    }
};