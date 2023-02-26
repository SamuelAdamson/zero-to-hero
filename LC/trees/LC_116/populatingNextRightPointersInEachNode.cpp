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
    void addNext(Node* root, Node* right, Node* rightLeft) {
        if(root == NULL) return;
        
        if(right == NULL && rightLeft != NULL) root->next = rightLeft;
        else root->next = right;
        
        Node* newRightLeft = (root->next != NULL) ? root->next->left : NULL;
        addNext(root->left, root->right, newRightLeft);
        addNext(root->right, NULL, newRightLeft);
    }
    
    Node* connect(Node* root) {
        /*  Set the next pointer on each node to the next right node. 
            That is the node that is on the same level as the current node 
            and directly to the right.
            
            Basically, on each level, we are passing the leftmost node of the right branch.
            This way we can use that to set the next node for rightmost leaves.
        */
        addNext(root, NULL, NULL);
        return root;
    }
};