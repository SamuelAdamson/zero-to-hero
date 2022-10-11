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
    // Bottom up approach
    int dfs(TreeNode* root) {
        if(root == NULL) return 0; // We are at the bottom level of the branch
        
        int lh = dfs(root->left);
        if(lh == -1) return -1;
        
        int rh = dfs(root->right);
        if(rh == -1) return -1;
        
        return (abs(lh-rh) <= 1) ? max(lh, rh) + 1 : -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};