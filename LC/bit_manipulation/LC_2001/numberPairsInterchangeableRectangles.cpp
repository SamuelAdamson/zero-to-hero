class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long result = 0;
        unordered_map<long long, int> rf;

        for(unsigned i = 0; i < rectangles.size(); i++) {
            int div = gcd(rectangles[i][0], rectangles[i][1]);
            
            long long key = ((long long)rectangles[i][0] / div) << 32;
            key |= (rectangles[i][1] / div);

            result += rf[key];
            rf[key]++;
        }

        return result;
    }
};
