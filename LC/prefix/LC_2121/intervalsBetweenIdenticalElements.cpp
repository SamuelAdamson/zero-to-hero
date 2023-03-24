class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> res(arr.size()); 

        // value : last index, prefix sum, # of prior occurrences
        unordered_map<int, tuple<int,long long,int>> p;    
        tuple<int, long long, int> last;
        
        long long diff;
        int i;

        for(i = 0; i < arr.size(); i++) {
            if(p.count(arr[i])) {
                last = p[arr[i]];

                diff = i - get<0>(last);
                diff += diff * get<2>(last);
                diff += get<1>(last);

                res[i] += diff;
                p[arr[i]] = {i, diff, get<2>(last)+1};
            }
            else {
                p[arr[i]] = {i, 0, 0};
            }
        }

        p.clear();
        for(i = arr.size()-1; i >= 0; i--) {
            if(p.count(arr[i])) {
                last = p[arr[i]];
                
                diff = get<0>(last) - i;
                diff += diff * get<2>(last);
                diff += get<1>(last);

                res[i] += diff;
                p[arr[i]] = {i, diff, get<2>(last)+1};
            }
            else {
                p[arr[i]] = {i, 0, 0};
            }
        }

        return res;
    }
};