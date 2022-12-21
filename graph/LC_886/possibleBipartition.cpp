class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int> &c, int s, int color) {
        if(c[s]) return color == c[s];
        c[s] = color;

        for(int node : g[s])
            if(!dfs(g, c, node, -1 * color)) return false;

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        /* Colors
            0 == Not Colored Yet (Not Visited)
            -1 == Black
            1 == Red
        */
        vector<vector<int>> graph(n);
        vector<int> color(n);
        
        for(unsigned i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }

        for(int i = 0; i < n; i++)
            if(!color[i] && !dfs(graph, color, i, 1)) return false;
    
        return true;
    }
};