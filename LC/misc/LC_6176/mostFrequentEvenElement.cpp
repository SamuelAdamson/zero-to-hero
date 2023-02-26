class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, maxVal = 10e5;
        
        for(int num: nums) {
            if(num%2==0) freq[num]++;
        }
        if(freq.size() == 0) return -1;
        
        for(pair keyVal: freq) {
            if(keyVal.second > maxFreq) {
                maxVal = keyVal.first;
                maxFreq = keyVal.second;
            }
            else if(keyVal.second == maxFreq) {
                maxVal = min(maxVal, keyVal.first); 
            }
        }
        
        return maxVal;
    }
};