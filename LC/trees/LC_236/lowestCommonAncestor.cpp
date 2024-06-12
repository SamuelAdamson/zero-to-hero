/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:

    TreeNode *lca;

    pair<bool, bool> dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(!root) return { false, false };

        pair<bool, bool> left = dfs(root->left, p, q);
        pair<bool, bool> right = dfs(root->right, p, q);

        if(lca)
            return { true,  true };

        bool p_found = left.first || right.first || (root == p);
        bool q_found = left.second || right.second || (root == q);

        if(p_found && q_found)
            lca = root;

        return { p_found, q_found };
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = NULL;
        dfs(root, p, q);

        return lca;
    }
};

