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
    int totalDistance;

    int dfs(TreeNode* root) {
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        totalDistance += abs(left) + abs(right);

        return (root->val - 1) + left + right;
    }

public:
    int distributeCoins(TreeNode* root) {
        totalDistance = 0;

        dfs(root);

        return totalDistance;
    }
};

