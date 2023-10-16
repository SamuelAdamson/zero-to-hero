class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex + 1, 0);
        r[0] = 1;

        for(unsigned i = 1; i <= rowIndex; i++) {
            r[i] = 1;
            for(unsigned j = i - 1; j >= 1; j--)
                r[j] = r[j] + r[j-1];
        }

        return r;
    }
};
