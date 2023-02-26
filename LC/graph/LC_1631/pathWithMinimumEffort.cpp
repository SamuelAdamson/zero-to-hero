class Solution {
public:
    bool dfs(vector<vector<int>>& h, vector<vector<int>>& v, int row, int col, int last, int k) {
        if(row < 0 || row >= h.size() || col < 0 || col >= h[0].size() || v[row][col] || abs(last - h[row][col]) > k) return false;
        if(row == h.size() - 1 && col == h[0].size() - 1) return true;
        v[row][col] = 1;
        
        return(
            dfs(h, v, row - 1, col, h[row][col], k)
            || dfs(h, v, row + 1, col, h[row][col], k)
            || dfs(h, v, row, col - 1, h[row][col], k)
            || dfs(h, v, row, col + 1, h[row][col], k)
        );
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 1e6, m, result;
        
        while(l <= r) {
            m = l + (r - l)/2;
            vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size()));
            
            if(dfs(heights, visited, 0, 0, heights[0][0], m)) {
                result = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return result;
    }
};