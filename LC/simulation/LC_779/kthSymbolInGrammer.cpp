class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<int> path;

        while(n > 0 && k > 1) {
            path.push_back(2 - (k % 2));
            k = k / 2 + (k % 2 != 0);
            n--;
        }

        reverse(path.begin(), path.end());

        vector<int> bits({0, 1});
        int result = 0;

        for(int i = 0; i < path.size(); i++) {
            result = bits[path[i]-1];
            if(result == 0)
                bits = {0, 1};
            else
                bits = {1, 0};
        }

        return result;
    }
};
