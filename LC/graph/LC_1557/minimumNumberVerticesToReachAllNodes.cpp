class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res, incoming(n);
        int i;

        for(i = 0; i < edges.size(); i++)
            incoming[edges[i][1]]++;

        for(i = 0; i < n; i++)
            if(incoming[i] == 0) res.push_back(i);

        return res;
    }
};