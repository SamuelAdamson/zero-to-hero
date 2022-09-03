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
    int checkGoodNodes(TreeNode* root, int currMax) {
        if(root == NULL) return 0;
        int isGoodNode = 0;
        
        if(root->val >= currMax) {
            currMax = root->val;
            isGoodNode++;
        }
            
        return (isGoodNode + checkGoodNodes(root->left, currMax) + checkGoodNodes(root->right, currMax));
    }
    
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return checkGoodNodes(root, root->val);
    }
};