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
    int helper(TreeNode *root, int curr, int limit) {
        curr += root->val;
        if(!root->left && !root->right) 
            return curr;
        
        int l = INT_MIN, r = INT_MIN;

        if(root->left) {
            l = helper(root->left, curr, limit);
            if(l < limit) {
                delete root->left;
                root->left = nullptr;
            }
        }

        if(root->right) {
            r = helper(root->right, curr, limit);
            if(r < limit) {
                delete root->right;
                root->right = nullptr;
            }
        }

        return max(l, r);
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root, 0, limit) < limit ? nullptr : root;
    }
};