class Solution {
public:
    bool dfs(vector<vector<int>> &g, vector<int> &v, int s, int e) {
        if(s == e) return true;
        v[s] = 1;

        for(int node : g[s]) if(!v[node] && dfs(g, v, node, e)) return true;
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<vector<int>> graph(n);
       vector<int> visited(n);
       for(int i = 0; i < edges.size(); i++) {
           graph[edges[i][0]].push_back(edges[i][1]);
           graph[edges[i][1]].push_back(edges[i][0]);
        }

        return dfs(graph, visited, source, destination);
    }
};