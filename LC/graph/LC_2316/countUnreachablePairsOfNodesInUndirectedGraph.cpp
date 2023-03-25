class Solution {
private:
    int dfs(const vector<vector<int>> &g, vector<bool> &v, int i) {
        int sz = 1;

        for(int node : g[i]) {
            if(v[node]) continue;

            v[node] = true;
            sz += dfs(g, v, node);
        }

        return sz;
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        long long res = 0;
        int sz, k = n;
        vector<bool> v(n);

        for(int i = 0; i < n; i++) {
            if(v[i]) continue;
            v[i] = true;

            sz = dfs(g, v, i);
            k -= sz;

            res += ((long long)sz * k);
        }

        return res;
    }
};