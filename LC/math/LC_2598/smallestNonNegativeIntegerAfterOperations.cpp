class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for(int n : nums) {
            int m = n % value;

            if(m < 0) freq[m + value]++;
            else freq[m]++;
        }
        
        int i = 0;
        while(freq[i%value]--) i++;

        return i;        
    }
};