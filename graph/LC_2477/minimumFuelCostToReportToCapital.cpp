class Solution {
public:
    int dfs(const vector<vector<int>> &g, vector<int> &s, vector<int> &v, int i) {
        // note here visited is marked as 1
        for(int node : g[i]) {
            if(!v[node]) {
                v[node] = 1;
                s[i] += dfs(g, s, v, node);
            }
        }

        return s[i];
    }

    long long dfs(const vector<vector<int>> &g, const vector<int> &s, vector<int> &v, int i, int seats) {
        // note here visited is marked as 0
        long long fuel = 0;

        for(int node : g[i]) {
            if(v[node]) {
                v[node] = 0;

                // ceiling(subtree size / seats)
                fuel += ((s[node] + seats - 1) / seats);
                fuel += dfs(g, s, v, node, seats);
            }
        }

        return fuel;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long fuel;
        int n = roads.size() + 1, i;
        
        vector<vector<int>> graph(n);         // city : all connected cities
        vector<int> sub(n, 1), visited(n);    // size of subtree at this node, visited

        // create graph
        for(i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }

        // first pass, dfs from 0, store size of each subtree and identify leaves
        visited[0] = 1;
        dfs(graph, sub, visited, 0);

        // second pass, computing fuel used
        visited[0] = 0;
        fuel = dfs(graph, sub, visited, 0, seats);

        return fuel;
    }
};