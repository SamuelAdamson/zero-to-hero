class Solution {
public:
    void backtrack(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int idx, int n) {
        path.push_back(idx);
        if(idx == n-1) result.push_back(path);
        else for(int next : graph[idx]) backtrack(graph, result, path, next, n);
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // We are told that the graph is acyclic so we don't need to mark visited
        int n = graph.size();
        vector<vector<int>> result;
        vector<int> path;
        
        backtrack(graph, result, path, 0, n);
        
        return result;
    }
};