class Solution {
public:
    void dfs(vector<vector<int>>& graph, int sRow, int n) {
        for(int i = 0; i < n; i++) {
            if(graph[sRow][i] == 1 && graph[i][i] == 1) {
                graph[i][i] = -1;
                dfs(graph, i, n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), numProvinces = 0;
        
        for(int i = 0; i < n; i ++) {
            if(isConnected[i][i] == 1) {
                numProvinces++;
                isConnected[i][i] = -1;
                dfs(isConnected, i, n);
            }
        }
        
        return numProvinces;
    }
};