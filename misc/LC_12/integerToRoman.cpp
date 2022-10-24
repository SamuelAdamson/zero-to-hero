class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        vector<vector<pair<int, char>>> numerals({
            {{1000, 'M'}, {100, 'C'}, {500, 'D'}},
            {{100, 'C'}, {10, 'X'}, {50, 'L'}},
            {{10, 'X'}, {1, 'I'}, {5, 'V'}}
        });
        
        
        for(int j = 0; j < numerals.size(); j++) {
            while(num >= numerals[j][0].first) {
                result.push_back(numerals[j][0].second);
                num -= numerals[j][0].first;
            }
            
            if(num >= (numerals[j][0].first - numerals[j][1].first)) {
                result.push_back(numerals[j][1].second);
                result.push_back(numerals[j][0].second);
                num -= (numerals[j][0].first - numerals[j][1].first);
            }
            else if(num >= numerals[j][2].first) {
                result.push_back(numerals[j][2].second);
                num -= numerals[j][2].first;
            }
            else if(num >= (numerals[j][2].first - numerals[j][1].first)) {
                result.push_back(numerals[j][1].second);
                result.push_back(numerals[j][2].second);
                num -= (numerals[j][2].first - numerals[j][1].first);
            }
        }
        
        while(num >= 1) {
            result.push_back('I');
            num--;
        }
        
        return result;
    }
};