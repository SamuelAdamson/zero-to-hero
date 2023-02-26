class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l, k, r, best, n = fruits.size();
        pair<int, int> fruitA, fruitB;

        // get first two unique fruits
        for(l = 0, r = 1; r < n && fruits[r] == fruits[0]; r++) l++;
        if(r >= n - 1) return n;

        fruitA = {fruits[l], l};
        fruitB = {fruits[r], r};
        best = ++r, l = 0;

        while(r < n) {
            if(fruits[r] != fruitA.first && fruits[r] != fruitB.first) {
                if(fruitA.second < fruitB.second) { // replace fruitA
                    l = fruitA.second + 1;
                    fruitA = {fruits[r], r};
                }
                else { // replace fruitB
                    l = fruitB.second + 1;
                    fruitB = {fruits[r], r};
                }
            }
            else if(fruits[r] == fruitA.first) fruitA.second = r;
            else fruitB.second = r;

            best = max(best, ++r - l);
        }

        return best;
    }
};