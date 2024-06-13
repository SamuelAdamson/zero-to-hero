/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:



public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        /* Root must be key */

        TreeNode *p, *c;

        /* No children, just remove node */
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }

        /* Only one child */
        if(root->left && !root->right) {
            c = root->left;
            delete root;
            return c;
        }
        if(root->right && !root->left) {
            c = root->right;
            delete root;
            return c;
        }

        /* Both children */
        // Need to find previous node in inorder traversal

        p = root, c = root->left;

        while(c->right) {
            p = c;
            c = c->right;
        }

        c->right = root->right;
        if(p != root) {
            p->right = c->left;
            c->left = root->left;
        }

        delete root;

        return c;
    }
};

