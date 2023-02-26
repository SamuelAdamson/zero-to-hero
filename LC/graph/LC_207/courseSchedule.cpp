class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& status, int i, int n) {
        for(int j : g[i]) {
            if(status[j] == -1) return false;
            else if(status[j] == 0) {
                status[j] = -1;
                if(!dfs(g, status, j, n)) return false;
            }
        }
        
        status[i] = 1;
        return true;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        for(vector<int> p : prerequisites) graph[p[0]].push_back(p[1]);
        
        // Status -1 : search in progress
        // Status 0 : unsearched
        // Status 1 : search complete
        vector<int> status (numCourses);
        
        for(int i = 0; i < numCourses; i++) {
            if(status[i] == 0) {
                status[i] = -1;
                if(!dfs(graph, status, i, numCourses)) return false;
            }
        }
        
        return true;
    }
};