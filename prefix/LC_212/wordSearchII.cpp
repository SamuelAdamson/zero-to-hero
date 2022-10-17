class Node {
public:
    char letter;
    Node* children[26];
    bool isWord;
    bool used;
    
    Node() {
        letter = ' ';
        memset(children, NULL, sizeof(children));
        isWord = false;
        used = false;
    }
    
    Node(char letter) {
        this->letter = letter;
        memset(children, NULL, sizeof(children));
        isWord = false;
        used = false;
    }
};

class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void add(string word) {
        Node* crawl = root;
        
        for(char letter : word) {
            if(crawl->children[letter-'a'] == NULL) crawl->children[letter-'a'] = new Node(letter);
            crawl = crawl->children[letter-'a'];
        }
        crawl->isWord = true;
    }
    
    void findWord(vector<vector<char>>& b, int r, int c, Node* node, string& word, vector<string>& result) {
        if(r >= 0 && r < b.size() && c >= 0 && c < b[0].size() && b[r][c] != '0' 
            && node->children[b[r][c]-'a'] != NULL) 
        {
            // Mark as visited, store next node
            Node* next = node->children[b[r][c]-'a'];
            word.push_back(b[r][c]);
            b[r][c] = '0';

            // Add to result if is word
            if(next->isWord && !next->used) {
                result.push_back(word); // Note this makes a copy
                next->used = true;
            }

            findWord(b, r-1, c, next, word, result);
            findWord(b, r+1, c, next, word, result);
            findWord(b, r, c-1, next, word, result);
            findWord(b, r, c+1, next, word, result);

            // Unmark
            word.pop_back();
            b[r][c] = next->letter;   
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        
        Trie t;
        for(string word : words) t.add(word);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                string word = "";
                t.findWord(board, i, j, t.root, word, result);
            }
        }
        
        return result;
    }
};