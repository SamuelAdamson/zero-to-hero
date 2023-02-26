class Solution {
private:
    vector<vector<int>> graph;
    vector<int> result, nc;

    // nc (Node Count) represents the number of nodes in the subtree
    //      of the ith node -> itself + each of its children

public:
    void dfs(unsigned source, unsigned parent) {
        for(int node : graph[source]) {
            if(node != parent) { // since this is a tree, this constitutes as visited check
                dfs(node, source);
                nc[source] += nc[node];
                result[source] += (nc[node] + result[node]);
            }
        }
    }

    void dfs(unsigned source, unsigned parent, int n) {
        for(int node : graph[source]) {
            if(node != parent) {
                // one connection farther from the source
                // one connection closer to the node that's not the source
                result[node] = (result[source] - nc[node]) + (n - nc[node]);
                dfs(node, source, n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        result.resize(n), nc.resize(n, 1);

        for(unsigned i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0, -1);
        dfs(0, -1, n);

        return result;
    }
};