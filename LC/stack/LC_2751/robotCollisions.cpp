class Robot {
public:
    int health, pos;
    char dir;
    
    Robot(int h, int p, char d) {
        health = h;
        pos = p;
        dir = d;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size(), i;
        vector<Robot*> robots(n), survived(n);
        
        for(i = 0; i < n; i++) {
            robots[i] = new Robot(healths[i], positions[i], directions[i]);
            survived[i] = robots[i];
        }
        
        sort(robots.begin(), robots.end(), [] (const Robot *r1, const Robot *r2) {
           return r1->pos < r2->pos; 
        });
        
        stack<Robot*> s;
        for(i = 0; i < n; i++) {
            Robot *curr = robots[i];
            
            if(curr->dir == 'R') s.push(curr);
            else {
                while(!s.empty() && curr->health > s.top()->health) {
                    curr->health--;
                    s.top()->health = 0;
                    s.pop();
                }
                
                if(!s.empty()) {
                    if(s.top()->health == curr->health) {
                        s.top()->health = 0;
                        s.pop();
                    }
                    else s.top()->health--;
                    curr->health = 0;
                }
            }
        }
        
        vector<int> res;
        for(i = 0; i < n; i++)
            if(survived[i]->health) res.push_back(survived[i]->health);
        
        return res;
    }
};