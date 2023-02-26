class Solution {
public:
    int minSetSize(vector<int>& arr) {
        /*  Find the size of the smallest set of integers such that
            if all occurrences are remvoed, the arrays size will be 
            cut in half (at least).
            
            Store the frequency of each integer using a map, sort the map by value
            and 
        */
        int target = arr.size() / 2, sum = 0, cnt = 0;
        unordered_map<int,int> freqMap;
        vector<int> freq;
        
        for(int num: arr) {
            freqMap[num] ++;
        }
        
        for(auto pair: freqMap) {
            freq.push_back(pair.second);
        }
        
        sort(freq.begin(), freq.end());
        for(int i = freq.size() - 1; i >= 0 && sum < target; i--, cnt++) {
            sum += freq[i];
        }
        
        return cnt;
    }
};