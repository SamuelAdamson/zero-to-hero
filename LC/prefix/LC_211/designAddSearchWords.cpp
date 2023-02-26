class Node {
public:
    Node* children[26];
    bool word;
    
    Node() {
        memset(children, NULL, sizeof(children));
        word = false;
    }
};


class WordDictionary {
public:
    Node* root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* crawl = root;
        
        for(char letter : word) {
            if(!crawl->children[letter-'a']) crawl->children[letter-'a'] = new Node();
            crawl = crawl->children[letter-'a'];
        }
        crawl->word = true;
    }
    
    bool search(string word) {
        return(dfs(word, 0, this->root));
    }

private:
    bool dfs(string& word, int i, Node* node) {
        if(node == NULL) return false;
        if(word.size() <= i) return node->word;
        
        if(word[i] == '.') {
            for(int j = 0; j < 26; j++) {
                if(dfs(word, i+1, node->children[j])) return true;
            }
            return false;
        }
        
        return dfs(word, i+1, node->children[word[i]-'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */