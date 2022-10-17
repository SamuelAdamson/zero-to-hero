class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool zero = false, one = false, two = false;
        
        for(int i = 0; i < triplets.size(); i++) {
            if(triplets[i][0]==target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]) zero = true;
            if(triplets[i][0]<=target[0] && triplets[i][1]==target[1] && triplets[i][2]<=target[2]) one = true;
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]==target[2]) two = true;
        }
        
        
        return zero && one && two;
    }
};