class Solution {
public:
    int reinitializePermutation(int n) {
        int maxOps = 0, currOps = 0, i, m;

        for(i = 0; i < n; i++) {
            m = i;
            currOps = 0;

            do {    
                currOps++;
                if(m & 1) m = n/2 + (m-1)/2;
                else m = m/2;
            } while(m != i);

            maxOps = max(currOps, maxOps);
        }

        return maxOps;
    }
};