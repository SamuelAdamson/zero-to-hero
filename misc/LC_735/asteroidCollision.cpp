class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        
        // Stack should hold asteroids moving right
        int i;
        for(i = 0; i < asteroids.size() && asteroids[i] < 0; i++) s.push_back(asteroids[i]);
        
        for(int j = i; j < asteroids.size(); j++) {
            if(asteroids[j] > 0) s.push_back(asteroids[j]);
            else {
                bool handled = false;
                int collision;
                
                while(s.size() > i && !handled) {
                    collision = s.back() + asteroids[j];
                    if(collision > 0) handled = true;
                    else {
                        if(collision == 0) handled = true;
                        s.pop_back();
                    }
                }
                
                if(!handled) {
                    s.push_back(asteroids[j]);
                    i = s.size();
                }
            }
        }
        
        return s;
    }
};