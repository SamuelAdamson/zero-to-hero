class Solution {
private:
    int cycleLength(const vector<int> &g, vector<int> &v, int node) {
        int next = g[node], len = 1;
        
        while(next != node)
            next = g[next], len++;

        return len;
    }

    int findCycle(const vector<int> &g, vector<int> &v, int i, int curr) {
        if(g[i] == -1) return -1;
        if(v[g[i]] == curr) return g[i];
        if(v[g[i]] != -1) return -1;

        v[g[i]] = curr;
        return findCycle(g, v, g[i], curr);
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), i, j, best = -1;
        vector<int> v(n, -1);

        for(i = 0; i < n; i++) {
            if(v[i] != -1) continue;

            v[i] = i;
            j = findCycle(edges, v, i, i);

            if(j != -1)
                best = max(best, cycleLength(edges, v, j));    
        }

        return best;
    }
};