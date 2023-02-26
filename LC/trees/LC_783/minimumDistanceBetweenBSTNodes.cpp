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
    int minDiff, lastVal;

    void inorder(TreeNode *root) {
        if(!root) return;
        
        inorder(root->left);
        minDiff = min(minDiff, abs(root->val - lastVal));
        lastVal = root->val;
        inorder(root->right);
    }

public:
    int minDiffInBST(TreeNode *root) {
        minDiff = 1e5+1, lastVal = -1e5;
        inorder(root);

        return minDiff;
    }
};