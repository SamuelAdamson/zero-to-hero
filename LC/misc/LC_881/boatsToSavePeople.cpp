class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0, i, j, n = people.size();

        for(i = 0, j = n-1; i < j; boats++) {
            if(people[i] + people[j] <= limit)
                i++, j--;
            else j--;
        }

        boats += (i == j);
        return boats;
    }
};