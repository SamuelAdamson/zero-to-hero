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
    int dfs(TreeNode *root, int val) {
        val *= 10;
        val += root->val;

        if(root->left && root->right)
            return dfs(root->left, val) + dfs(root->right, val);
        
        if(root->left)
            return dfs(root->left, val);

        if(root->right)
            return dfs(root->right, val);

        return val;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};