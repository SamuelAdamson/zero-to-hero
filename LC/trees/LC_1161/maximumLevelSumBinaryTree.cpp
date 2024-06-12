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
    int maxLevelSum(TreeNode* root) {
        int best_level = 0, max_sum = INT_MIN;
        int level = 1, curr_sum, sz;

        queue<TreeNode*> q({ root });

        while(!q.empty()) {
            sz = q.size();
            curr_sum = 0;

            while(sz > 0) {
                curr_sum += q.front()->val;

                if(q.front()->left)
                    q.push(q.front()->left);

                if(q.front()->right)
                    q.push(q.front()->right);
                
                q.pop();
                sz--;
            }

            if(curr_sum > max_sum) { // strictly greater
                max_sum = curr_sum;
                best_level = level;
            }

            level++;
        }

        return best_level;
    }
};

