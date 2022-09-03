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
    void merge(TreeNode* root1, TreeNode* root2) {
        if(root1->left == NULL) root1->left = root2->left;
        else if(root2->left != NULL) {
            root1->left->val += root2->left->val;
            merge(root1->left, root2->left);
        }
        
        if(root1->right == NULL) root1->right = root2->right;
        else if(root2->right != NULL) {
            root1->right->val += root2->right->val;
            merge(root1->right, root2->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /*  Merge two trees, if overlapping nodes then sum.
            
            Store the merged tree under root1. Recursively traverse tree 
            at each node if node under root1 is null, point it to the corresponding 
            node under root2. Otherwise, add together values.
        */
        if(root1 != NULL && root2 != NULL) root1->val += root2->val;
        else if(root1 == NULL) return root2;
        else if(root2 == NULL) return root1;
        
        merge(root1, root2);
        return root1;
    }
};