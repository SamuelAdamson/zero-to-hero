class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& status, vector<int>& result, int i, int n) {
        bool possible = true;
        
        for(int j = 0; j < n && possible; j++) {
            if(graph[i][j]) {
                if(status[j] == -1) possible = false;
                else if(status[j] == 0) {
                    status[j] = -1;
                    possible &= dfs(graph, status, result, j, n);
                }
            }
        }
        
        status[i] = 1;
        result.push_back(i);
        return possible;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses, vector<int>(numCourses));
        for(vector<int> p : prerequisites) graph[p[0]][p[1]] = 1; 
        
        // Status -1 : search in progress
        // Status 0 : search not started
        // Status 1 : search complete
        vector<int> status(numCourses), result;
        bool possible = true;
        
        for(int i = 0; i < numCourses && possible; i++) {
            if(status[i] == 0) {
                status[i] = -1; 
                possible &= dfs(graph, status, result, i, numCourses);
            }
        }
        
        
        return possible ? result : vector<int>();
    }
};