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
public:
    TreeNode* add(TreeNode* root, int val, int depth) {
        if(root != NULL) {
            if(depth == 1) {
                TreeNode *newLeft = new TreeNode(val, root->left, NULL);
                TreeNode *newRight = new TreeNode(val, NULL, root->right);
                root->left = newLeft;
                root->right = newRight;
            }
            else {
                root->left = add(root->left, val, depth-1);
                root->right = add(root->right, val, depth-1);
            }   
        }   
        
        return root;
    }
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }
        
        return add(root, val, depth-1);
    }
};