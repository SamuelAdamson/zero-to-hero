class Node {
public:
    vector<Node*> children;
    bool isEnd;
    
    Node() {
        isEnd = false;
        children.assign(26, NULL);
    }
};

class Trie {
private:
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* crawl = root;
        
        for(char ch : word) {
            if(crawl->children[ch - 'a'] == NULL) crawl->children[ch - 'a'] = new Node();
            crawl = crawl->children[ch - 'a'];
        }
        
        crawl->isEnd = true;
    }
    
    bool search(string word) {
        Node* crawl = root;
        
        for(char ch : word) {
            if(crawl->children[ch - 'a'] == NULL) return false;
            crawl = crawl->children[ch - 'a'];
        }
        
        return crawl->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* crawl = root;
        
        for(char ch : prefix) {
            if(crawl->children[ch - 'a'] == NULL) return false;
            crawl = crawl->children[ch - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */