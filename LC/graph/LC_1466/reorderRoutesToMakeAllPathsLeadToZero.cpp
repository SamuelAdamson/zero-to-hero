class Solution {
public:
    int dfs(const vector<vector<int>> &dg, const vector<vector<int>> &ug, vector<bool> &v, int i) {
        int reorders = 0;

        for(int node : dg[i])
            if(!v[node]) reorders++;

        for(int node : ug[i]) {
            if(v[node]) continue;
            v[node] = true;
            reorders += dfs(dg, ug, v, node);
        }

        return reorders;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> dg(n);
        vector<vector<int>> ug(n);
        vector<bool> visited(n);

        for(int i = 0; i < n-1; i++) {
            dg[connections[i][0]].push_back(connections[i][1]);
            ug[connections[i][0]].push_back(connections[i][1]);
            ug[connections[i][1]].push_back(connections[i][0]);
        }

        visited[0] = true;
        return dfs(dg, ug, visited, 0);
    }
};