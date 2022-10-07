class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<vector<int>> graph (n, vector<int>());
        queue<int> leaves;
        
        vector<int> result, degrees(n);
        int curr, sz;
        
        for(int i = 0; i < n-1; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            degrees[edges[i][0]]++;
            graph[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(degrees[i] == 1) leaves.push(i);
        }
        
        while(!leaves.empty()) {
            sz = leaves.size();
            result = {};
            
            for(int k = 0; k < sz; k++) {
                curr = leaves.front();
                leaves.pop();   
                
                result.push_back(curr);
                for(int node : graph[curr]) {
                    degrees[node]--;
                    if(degrees[node] == 1) leaves.push(node);
                }
            }
            
        }
        
        return result;
    }
};