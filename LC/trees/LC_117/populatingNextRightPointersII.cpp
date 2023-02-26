/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root) {
        queue<Node*> q({root});
        Node *last, *curr;
        
        while(!q.empty()) {
            q.push(NULL);
            last = q.front();
            q.pop();
            
            while(last != NULL) {
                curr = q.front();
                q.pop();
                
                if(last->left != NULL) q.push(last->left);
                if(last->right != NULL) q.push(last->right);
                
                last->next = curr;
                last = curr;
            }
        }
        
    }
    
    Node* connect(Node* root) {
        if(root != NULL) bfs(root);
        return root;
    }
};