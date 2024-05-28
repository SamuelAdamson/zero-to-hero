class Solution {
public:
    string decodeString(string s) {
        int curr_multi = 0; // used solely for storing multi-digit numbers

        stack<int> multis;
        stack<string> st({ "" });

        for(char c : s) {
            if(isdigit(c)) {
                curr_multi *= 10;
                curr_multi += (c - '0');
            }
            else if(c == '[') {
                multis.push(curr_multi);
                curr_multi = 0;
                st.push("");
            }
            else if(c == ']') {
                int m = multis.top();
                multis.pop();

                string repeated = "";

                while(m > 0) {
                    repeated.append(st.top());
                    m--;
                }

                st.pop();
                st.top().append(repeated);
            }
            else { // standard letter
                st.top().push_back(c);
            }
        }

        return st.top();
    }
};

