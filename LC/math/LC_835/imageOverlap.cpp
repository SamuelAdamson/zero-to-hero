class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), best = 0;
        vector<int> img1Indices;
        vector<int> img2Indices;
        unordered_map<int, int> diff;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j]) img1Indices.push_back(i*100 + j);
                if(img2[i][j]) img2Indices.push_back(i*100 + j);
            }
        }
        
        for(int i = 0; i < img1Indices.size(); i++) {
            for(int j = 0; j < img2Indices.size(); j++) {
                diff[img1Indices[i] - img2Indices[j]]++;
                best = max(best, diff[img1Indices[i] - img2Indices[j]]);
            }
        }
        
        return best;
    }
};