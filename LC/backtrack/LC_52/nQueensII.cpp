class Solution {
private:
    int res;

    void backtrack(
        vector<bool> &cols,
        vector<bool> &tr_bl,
        vector<bool> &tl_br,
        int n, int r
    ) {
        if(r == n) res++;
        else {
            for(int c = 0; c < n; c++) {
                if(cols[c] || tr_bl[r+c] || tl_br[c-r+(n-1)]) continue;

                cols[c] = true;
                tr_bl[r+c] = true;
                tl_br[c-r+(n-1)] = true;

                backtrack(cols, tr_bl, tl_br, n, r+1);

                cols[c] = false;
                tr_bl[r+c] = false;
                tl_br[c-r+(n-1)] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        res = 0;
        vector<bool> cols(n);

        // tr_bl : row + col
        // tl_br : col - row + (n - 1)
        vector<bool> tr_bl(2 * n - 1), tl_br(2 * n - 1);

        backtrack(cols, tr_bl, tl_br, n, 0);
        return res;
    }
};