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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        queue<TreeNode*> q({ root });
        int sz;
        TreeNode *front;

        while(!q.empty()) {
            sz = q.size();

            while(sz > 0) {
                front = q.front();
                q.pop();
                sz--;

                if(front->left)
                    q.push(front->left);

                if(front->right)
                    q.push(front->right);

                if(!sz)
                    result.push_back(front->val);
            }
        }

        return result;
    }
};

