class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        /*  We can use the vector of codes as a map, wher the index
            of the letter is that letter in code (0 - 26). Simply
            store unique words in a set or map and find the 
            size of the set
        */

        vector<string> codes {  // a is index 0, b is index 1, so on
            ".-","-...","-.-.","-..",
            ".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.",
            "---",".--.","--.-",".-.","...",
            "-","..-","...-",".--","-..-",
            "-.--","--.."
        };
        
        unordered_set<string> freq;
        
        for(string word : words) {
            string morse = "";
            for(char c : word) {
                morse.append(codes[c - 'a']);   
            }
            
            freq.insert(morse);
        }
        
        return freq.size();
    }
};