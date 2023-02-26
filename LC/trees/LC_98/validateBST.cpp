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
    bool dfs(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if(root == NULL) return true;
        if((lower != NULL && root->val <= lower->val) || (upper != NULL && root->val >= upper-> val)) return false;
        
        TreeNode *newLower, *newUpper;
        
        if(lower == NULL) newLower = root;
        else newLower = (root->val > lower->val) ? root : lower;
        
        if(upper == NULL) newUpper = root;
        else newUpper = (root->val < upper->val) ? root : upper;
        
        return dfs(root->left, lower, newUpper) && dfs(root->right, newLower, upper);
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
};