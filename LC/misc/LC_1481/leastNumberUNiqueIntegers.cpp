class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> f;
        for(int n : arr) f[n]++;

        vector<int> v;
        for(auto i = f.begin(); i != f.end(); i++) 
            v.push_back(i->second);

        make_heap(v.begin(), v.end(), greater<int>());
        while(!v.empty() && k >= v.front()) {
            k -= v.front();
            pop_heap(v.begin(), v.end(), greater<int>());
            
            if(k >= 0) v.pop_back();
        }

        return v.size();
    }
};