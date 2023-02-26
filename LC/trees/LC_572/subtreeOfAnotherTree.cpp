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
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) return root == subRoot;
        if(root->val != subRoot->val) return false;
        return (
            dfs(root->left, subRoot->left) && 
            dfs(root->right, subRoot->right)
        );
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool result = false;
        if(root != NULL) {
            if(root->val == subRoot->val) result = dfs(root, subRoot);
            result = result || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        } 
        
        return result;
    }
};