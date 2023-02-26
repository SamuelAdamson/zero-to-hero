class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length(), spaces = 0;
        
        if(sentence[n-1] != sentence[0]) return false;
        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ') {
                if(sentence[i-1] == sentence[i+1]) return true; 
                spaces++;   
            }
        }
        
        return spaces <= 0;
    }
};