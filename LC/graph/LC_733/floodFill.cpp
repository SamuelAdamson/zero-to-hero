class Solution {
public:
    void dfs(
        vector<vector<int>>& image, 
        int nRows, int nCols, int row, int col, 
        int startColor, int fillColor
    ) {    
        if(row >= 0 && row < nRows && col >= 0 && col < nCols && image[row][col] == startColor) {
            image[row][col] = fillColor;
            dfs(image, nRows, nCols, row-1, col, startColor, fillColor);
            dfs(image, nRows, nCols, row, col-1, startColor, fillColor);
            dfs(image, nRows, nCols, row+1, col, startColor, fillColor);
            dfs(image, nRows, nCols, row, col+1, startColor, fillColor);
        }
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        /* Graph connected via adjacency. Given a starting cell, fill all cells 
           of the same color (integer label) with the color passed to the function.
            
           Use dfs to recursively traverse the connected cells. Only cover cells
           that have the same color as startring cell.
        */
        int startColor = image[sr][sc];
        if(startColor != color) {
            dfs(image, image.size(), image[0].size(), sr, sc, startColor, color);
        }
        
        return image;
    }
};