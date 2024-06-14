class Solution {
private:

    unordered_map<string, unordered_map<string, double>> g;

    double dfs(
        double curr_val, 
        const string &op, 
        const string &end_op,
        unordered_map<string, bool> &v
    ) {
        double result;
        unordered_map<string, double> neighbors = g[op];

        if(neighbors.count(end_op))
            return curr_val * neighbors[end_op];

        for(auto p : neighbors) {
            if(v[p.first]) continue;
            v[p.first] = true;

            result = dfs(curr_val * p.second, p.first, end_op, v);

            if(result != -1.0)
                return result;
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) { 
        unsigned i, n = queries.size();
        vector<double> result(n);

        for(i = 0; i < equations.size(); i++) {
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        
        for(i = 0; i < n; i++) {
            if(!g.count(queries[i][0]) || !g.count(queries[i][1])) {
                result[i] = -1.0;
                continue;
            }

            if(queries[i][0] == queries[i][1]) {
                result[i] = 1.0;
                continue;
            }

            unordered_map<string, bool> v;
            v[queries[i][0]] = true;
        
            result[i] = dfs(1.0, queries[i][0], queries[i][1], v);
        }

        return result;
    }
};

