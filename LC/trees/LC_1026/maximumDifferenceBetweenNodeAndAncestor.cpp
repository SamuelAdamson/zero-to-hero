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
    int dfs(TreeNode *root, int minVal, int maxVal) {
        if(root) {
            maxVal = max(root->val, maxVal);
            minVal = min(root->val, minVal);

            int best = max(dfs(root->left, minVal, maxVal), dfs(root->right, minVal, maxVal));
            return max(maxVal - minVal, best);
        }

        return maxVal - minVal;
    }

    int maxAncestorDiff(TreeNode *root) {
        int minVal = root->val, maxVal = root->val;
        return dfs(root, minVal, maxVal);
    }
};