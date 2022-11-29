class RandomizedSet {
private:
    unordered_map<int, int> s;
    vector<int> sv;
    int n;
    
public:
    RandomizedSet() { 
        n = 0;
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        
        sv.push_back(val);
        s[val] = n;
        
        n++;
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end()) return false;
        
        int i = s[val];
        s.erase(val);
        
        swap(sv[i], sv[n-1]);
        sv.pop_back();
        n--;    
        
        if(i < n) s[sv[i]] = i;
        return true;
    }
    
    int getRandom() {
        return sv[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */