class Solution {
public:
    void dfs(
        const vector<vector<pair<int, int>>> &graph, vector<int> &costs,
        int s, int d, int k, int depth, int cost
    ) {
        if(depth > k || s == d) return;

        for(auto p : graph[s]) {
            int nc = cost + p.second;
            
            if(costs[p.first] > 0 && costs[p.first] <= nc && costs[d] > 0) continue;
            costs[p.first] = nc;
            dfs(graph, costs, p.first, d, k, depth+1, nc);
        }

    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        
        // setup graph
        // source : (destination, price)
        for(int i = 0; i < flights.size(); i++) 
            g[flights[i][0]].push_back({flights[i][1], flights[i][2]});

        // perform dfs from source node keeping track of depth, each dfs
        //  will return the distance it took to reach the end node or -1
        // we take the minimum of these dfs values
        
        // cost to reach a node (-1 represents unvisited)
        // this represents a visited check, but we continue if the current cost
        //  to reach the ith node is less than the current value in this list
        vector<int> costs(n, -1);
        costs[src] = 0;

        dfs(g, costs, src, dst, k, 0, 0);
        
        return costs[dst];
    }
};