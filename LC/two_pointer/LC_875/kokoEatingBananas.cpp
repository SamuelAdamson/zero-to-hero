class Solution {
private:
    bool checkSpeed(const vector<int> &piles, int h, int speed) {
        int hours = 0;

        for(int n : piles) {
            hours += n / speed + (n % speed > 0);
            if(hours > h) return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), m;

        while(low < high) {
            m = low + (high - low)/2;

            if(checkSpeed(piles, h, m)) high = m;
            else low = m + 1;
        }

        return low;
    }
};