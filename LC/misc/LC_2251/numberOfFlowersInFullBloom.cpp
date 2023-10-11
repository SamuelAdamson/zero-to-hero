class Solution {
private:

    int binarySearchL(const vector<int> &v, int target) {
        int m, l = 0, h = v.size()-1;
        while(l < h) {
            m = l + (h-l)/2;
            if(v[m] < target)
                l = m + 1;
            else
                h = m;
        }
        return l;
    }

    int binarySearchH(const vector<int> &v, int target) {
        int m, l = 0, h = v.size()-1;
        while(l <= h) {
            m = l + (h-l)/2;
            if(v[m] <= target)
                l = m+1;
            else
                h = m-1;
        }
        return max(0, h);
    }

public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts(flowers.size()), ends(flowers.size());
        for(unsigned i = 0; i < flowers.size(); i++) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> result(people.size());
        for(unsigned i = 0; i < people.size(); i++) {
            int s_i = binarySearchH(starts, people[i]);
            int e_i = binarySearchL(ends, people[i]);

            if(people[i] >= starts[s_i] && people[i] <= ends[e_i]) s_i++;
            result[i] = s_i - e_i;
        }

        return result;
    }
};
