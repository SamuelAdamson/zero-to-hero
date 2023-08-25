class Solution {
private:
    string combineWords(const vector<string> &words, int maxWidth, int charCount, int wordCount) {
        string result;
        int spaces = maxWidth - charCount;

        if(wordCount == 1) {
            result.append(words[0]);
            while(spaces > 0) {
                result.push_back(' ');
                spaces--;
            }
        }
        else {
            int denom = wordCount - 1, i, j;
            int r = spaces % denom, q = spaces / denom;

            for(i = 0; i < denom; i++) {
                result.append(words[i]);
                for(j = 0; j < q; j++) result.push_back(' ');
                if(r) {
                    result.push_back(' ');
                    r--;
                }
            }
            result.append(words[i]);
        }

        return result;
    }

    string combineWordsLeftJustify(const vector<string> &words, int maxWidth, int charCount, int wordCount) {
        string result;
        int spaces = maxWidth - charCount;

        for(int i = 0; i < wordCount - 1; i++) {
            result.append(words[i]);
            result.push_back(' ');
            spaces--;
        }

        result.append(words[wordCount - 1]);
        while(spaces > 0) {
            result.push_back(' ');
            spaces--;
        }

        return result;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result, currWords;
        int charCount = 0, wordCount = 0, len, tLen;

        for(const string &word : words) {
            len = word.size();
            tLen = len + charCount + wordCount;

            if(tLen > maxWidth) {
                if(wordCount) result.push_back(combineWords(currWords, maxWidth, charCount, wordCount));

                currWords = { word };
                charCount = len;
                wordCount = 1;
            }
            else if(tLen == maxWidth) {
                currWords.push_back(word);
                charCount += len;
                wordCount++;
                result.push_back(combineWords(currWords, maxWidth, charCount, wordCount));
                
                currWords.clear();
                charCount = wordCount = 0;
            }
            else {
                currWords.push_back(word);
                charCount += len;
                wordCount++;
            }
        }

        if(wordCount) result.push_back(combineWordsLeftJustify(currWords, maxWidth, charCount, wordCount));
        return result;
    }
};