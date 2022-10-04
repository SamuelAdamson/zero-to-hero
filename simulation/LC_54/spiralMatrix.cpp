class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minR = 0, maxR = matrix.size() - 1, minC = 0, maxC = matrix[0].size() - 1;
        vector<int> result;
        
        while(minR <= maxR || minC <= maxC) {
            for(int i = minC; i <= maxC && minR <= maxR; i++) result.push_back(matrix[minR][i]);
            minR++;
            
            for(int i = minR; i <= maxR && minC <= maxC; i++) result.push_back(matrix[i][maxC]);
            maxC--;
            
            for(int i = maxC; i >= minC && minR <= maxR; i--) result.push_back(matrix[maxR][i]);
            maxR--;
            
            for(int i = maxR; i >= minR && minC <= maxC; i--) result.push_back(matrix[i][minC]);
            minC++;
        }
        
        return result;
    }
};