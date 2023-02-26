class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0, r = tokens.size() - 1, score = 0, maxScore = 0;
        bool keepLooping = true;
        sort(tokens.begin(), tokens.end());
        
        while(l <= r && keepLooping) {
            if(power >= tokens[l]) {
                power -= tokens[l];
                l++;
                score++;
                maxScore = max(score, maxScore);
            }
            else if(score > 0) {
                power += tokens[r];
                r--;
                score--;
            }
            else keepLooping = false;
        }
        
        return maxScore;
    }
};