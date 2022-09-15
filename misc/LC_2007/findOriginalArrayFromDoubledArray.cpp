class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        vector<int> freqMap(10e5 + 1), result;
        int n = freqMap.size();
        
        for(int num : changed) {
            freqMap[num]++;
        }
        
        for(int i = 0; i < n / 2; i++) {
            while(freqMap[i] > 0) {
                freqMap[i]--;
                freqMap[2*i]--;
                result.push_back(i);
            }
            if(freqMap[2*i] != 0 && (4*i >= n || freqMap[4*i] == 0)) return {};
        }
        
        return result;
    }
};