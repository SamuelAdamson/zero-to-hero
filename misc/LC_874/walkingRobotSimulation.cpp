class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // x coord : [y coord]
        unordered_map<int, unordered_set<int>> obsMap;
        for(int i = 0; i < obstacles.size(); i++) {
            obsMap[obstacles[i][0]].insert(obstacles[i][1]);
        }

        int xDir = 0, yDir = 1;
        int x = 0, y = 0, distance = 0;

        for(int command : commands) {
            if(command < 0) {
                swap(xDir, yDir);
                if(command == -1) yDir *= -1;
                else xDir *= -1;
            }
            else {
                bool obstacle = false;
                for(int i = 0; i < command && !obstacle; i++) {
                    x += xDir, y += yDir;

                    if(obsMap[x].count(y)) {
                        x -= xDir, y -= yDir;
                        obstacle = true;
                    }

                    distance = max(distance, x*x + y*y);
                }
            }
        }

        return distance;
    }
};