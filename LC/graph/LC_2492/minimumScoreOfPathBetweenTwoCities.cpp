class Solution {
public:
    int dfs(vector<vector<pair<int, int>>> &g, vector<int> &v, int best, int city) {
        for(auto p : g[city]) {
            best = min(best, p.second);
            if(!v[p.first]) {
                v[p.first] = 1;    
                best = min(best, dfs(g, v, best, p.first));
            }
        }
        
        return best;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        // key (index) : city - 1
        // value : list of cities [path, city]
        vector<vector<pair<int, int>>> graph(n);
        vector<int> visited(n);
        
        for(int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]-1].push_back(make_pair(roads[i][1]-1, roads[i][2]));
            graph[roads[i][1]-1].push_back(make_pair(roads[i][0]-1, roads[i][2]));
        }
        
        visited[0] = 1;
        return dfs(graph, visited, 1e4, 0);
    }
};