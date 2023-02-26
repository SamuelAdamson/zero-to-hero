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
    TreeNode* dfs(TreeNode *root, TreeNode *next) {        
        TreeNode *right = root->right ? dfs(root->right, next) : next;
        root->right = root->left ? dfs(root->left, right) : right;
        
        root->left = NULL;
        return root;
    }
    
    void flatten(TreeNode* root) {
        if(root) dfs(root, NULL);
    }
};