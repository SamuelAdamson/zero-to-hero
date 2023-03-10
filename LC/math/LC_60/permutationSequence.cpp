class Solution {
private:
    int factorial(int h) {
        if(h <= 1) return 1;
        return h * factorial(h-1);
    }

    void recurse(string &res, vector<char> &v, int n, int m, int k) {
        if(n == 1) {
            res.push_back(v[0]);
            return;
        }

        int idx = k/m;
        res.push_back(v[idx]);
        v.erase(v.begin() + idx);

        n--;
        recurse(res, v, n, m/n, k%m);
    }

public:
    string getPermutation(int n, int k) {
        vector<char> v(n);
        for(int i = 0; i < n; i++) v[i] = i+1+'0';

        string res;
        int m = factorial(n-1);

        recurse(res, v, n, m, k-1);
        return res;
    }
};