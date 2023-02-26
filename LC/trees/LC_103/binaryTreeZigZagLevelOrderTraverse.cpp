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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q({root});
        int sz, k;
        TreeNode *curr;

        // true : left -> right
        // false : right -> left
        bool direction = true;

        while(!q.empty()) {
            sz = q.size();
            vector<int> level(sz);

            for(k = 0; k < sz; k++) {
                curr = q.front();
                q.pop();

                if(direction) level[k] = curr->val;
                else level[sz-k-1] = curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            direction = !direction; // flip direction
            result.push_back(level);
        }
        
        return result;
    }
};