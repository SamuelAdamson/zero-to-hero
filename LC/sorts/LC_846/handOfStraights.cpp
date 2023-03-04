class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
        map<int, int> freq; 

        for(int n : hand) freq[n]++;
        for(auto i = freq.begin(); i != freq.end(); i++) {
            if(!i->second) continue;

            for(int s = i->first+1; s < i->first + groupSize; s++) {
                if(freq[s] < i->second) return false;
                freq[s] -= i->second;
            }
        }

        return true;
    }
};