class Solution {
public:
    int compress(vector<char>& chars) {
        char last = chars[0];
        int curr = 1, j = 0, i;

        for(i = 1; i < chars.size(); i++) {
            if(chars[i] == last) curr++;
            else {
                chars[j++] = last;
                if(curr > 1)
                    for(char c : to_string(curr)) chars[j++] = c;

                last = chars[i];
                curr = 1;
            }
        }        

        chars[j++] = last;        
        if(curr > 1)
            for(char c : to_string(curr)) chars[j++] = c;

        return j;
    }
};