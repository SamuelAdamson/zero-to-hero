class Solution {
public:
    int backtrack(vector<string>& arr, int i, vector<int>& mask, int currLen) {
        int maxLen = currLen;
        vector<int> maskCopy(mask);
        
        for(int j = i; j < arr.size(); j++) {
            bool valid = true;
            for(int k = 0; valid && k < arr[j].length(); k++) {
                if(mask[arr[j][k]-'a']) valid = false;
                else mask[arr[j][k]-'a'] = 1;
            }
            
            if(valid) {
                maxLen = max(
                    maxLen, 
                    backtrack(arr, j + 1, mask, currLen + arr[j].length())
                );
            }
            
            mask = maskCopy;
        }
        
        return maxLen;
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> mask(26);
        return backtrack(arr, 0, mask, 0);
    }
};