class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), result = 0, link, linkIdx;
        unordered_map<int, int> idx, dp;
        
        for(int i = 0; i < n; i++) idx[arr[i]] = i;      
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                link = arr[i] - arr[j];
                if(link < arr[j] && idx.count(link)) {
                    // Now, we know there is a value that precedes arr[j] and arr[i]
                    //  and links the two together for a fibonacci sequence
                    
                    // So, store in dp table, based on last length of subsequence of link
                    linkIdx = idx[link];
                    dp[j * n + i] = dp[linkIdx * n + j] + 1; // hashing dp essentially
                    result = max(result, dp[j * n + i] + 2);
                }
            }
        }

        return result > 2 ? result : 0;
    }
};
Console
