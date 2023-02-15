class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // node : paths (node, color)
        // red : 0
        // blue : 1
        vector<vector<pair<int, int>>> graph(n);
        vector<int> result(n, -1);
        int i;

        // make graph
        for(i = 0; i < redEdges.size(); i++) graph[redEdges[i][0]].push_back({redEdges[i][1], 0});
        for(i = 0; i < blueEdges.size(); i++) graph[blueEdges[i][0]].push_back({blueEdges[i][1], 1});

        // perform bfs from node 0, only progress along alternating colors
        int node, level = 0, sz, lastColor;
        queue<pair<int, char>> q({{0, -1}});
        
        // avoid cycles
        vector<vector<int>> visited(n, vector<int>(2));

        while(!q.empty()) {
            sz = q.size();

            for(i = 0; i < sz; i++) {
                node = q.front().first;
                lastColor = q.front().second;
                q.pop();

                // store result
                if(result[node] < 0) result[node] = level;

                for(auto p : graph[node]) {
                    if(visited[p.first][p.second] || lastColor == p.second) continue;
                    visited[p.first][p.second] = 1;
                    q.push({p.first, p.second});
                }
            }

            level++;
        }

        return result;
    }
};