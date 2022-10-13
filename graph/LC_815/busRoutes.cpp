class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        
        // Map stops -> stop : bus
        unordered_map<int, vector<int>> stops;
        for(int i = 0; i < routes.size(); i++) {
            for(int stop : routes[i]) stops[stop].push_back(i);
        }
        
        // Visited stops
        unordered_set<int> vs({source}), vb;
        queue<int> stopQ({source});
        int level = 0, sz, curr;
        
        while(!stopQ.empty()) {
            level++;
            sz = stopQ.size();
            
            for(int i = 0; i < sz; i++) {
                curr = stopQ.front();
                stopQ.pop();
                
                for(int bus : stops[curr]) {
                    if(vb.find(bus) == vb.end()) {
                        vb.insert(bus);
                        for(int stop : routes[bus]) {
                            if(stop == target) return level;
                            if(vs.find(stop) == vs.end()) {
                                vs.insert(stop);
                                stopQ.push(stop);
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};