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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while(!s.empty() || curr != NULL) {
            if(curr != NULL) {
                s.push(curr);
                curr =  curr->left;
            }
            else {
                curr = s.top();
                s.pop();
                
                if(k == 1) return curr->val;
                k--;
                
                curr = curr->right;
            }
            
        }
        
        // We do not expect to reach here
        return 0;
    }
};