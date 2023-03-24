class Solution {
public:
    void dfs(const vector<vector<int>> &g, vector<bool> &v, int i, int n) {
        for(int node : g[i]) {
            if(v[node]) continue;

            v[node] = true;
            dfs(g, v, node, n);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        vector<vector<int>> g(n);
        for(int i = 0; i < connections.size(); i++) {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }

        int islands = 0;
        vector<bool> v(n);

        for(int i = 0; i < n; i++) {
            if(v[i]) continue;
            
            v[i] = true;
            islands++;

            dfs(g, v, i, n);
        }

        return islands - 1;
    }
};