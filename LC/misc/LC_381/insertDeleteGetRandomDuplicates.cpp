class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> s;
    vector<int> sv;
    int n;
    
public:
    RandomizedCollection() {
        n = 0;
    }
    
    bool insert(int val) {
        bool present = s.find(val) == s.end();
        
        s[val].insert(n);
        sv.push_back(val);
        
        n++;
        return present;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end()) return false;
        auto it = s[val].begin();
        
        int i = *it;
        int end = n-1;
        
        s[val].erase(it);
        swap(sv[i], sv[end]);
        sv.pop_back();
        n--;
        
        if(s[val].empty()) s.erase(val);
        if(i < n) {
            s[sv[i]].erase(end);
            s[sv[i]].insert(i);
        }
        
        return true;
    }
    
    int getRandom() {
        return sv[rand() % n];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */