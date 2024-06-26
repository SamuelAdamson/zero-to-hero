class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, m, r = letters.size();

        while(l < r) {
            m = l + ((r - l) / 2);

            if(letters[m] <= target)
                l = m + 1;
            else
                r = m;
        }

        return letters[l % letters.size()];
    }
};

