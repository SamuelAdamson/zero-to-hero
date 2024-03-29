/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    int i;

    NestedInteger getInteger(const string &s) {
        string val;
        while(i < s.length() && (isdigit(s[i]) || s[i] == '-'))
            val.push_back(s[i++]);
        
        return NestedInteger(stoi(val));
    }

    NestedInteger helper(const string &s) {
        if(isdigit(s[i]) || s[i] == '-') return getInteger(s);
        NestedInteger root;

        i++;
        while(i < s.length() && s[i] != ']') {
            if(s[i] == ',') i++;
            root.add(helper(s));
        }
        
        i++;
        return root;
    }

public:
    NestedInteger deserialize(string s) {
        i = 0;
        return helper(s);
    }
};


