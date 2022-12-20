class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>& v, int s) {
        for(int room : rooms[s]) {
            if(!v[room]) {
                v[room] = 1;
                dfs(rooms, v, room);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        visited[0] = 1;

        dfs(rooms, visited, 0);

        for(int n : visited) if(!n) return false;
        return true;
    }
};