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
    long long kthLargestLevelSum(TreeNode* root, int k) { 
        priority_queue<long long> pq;
        queue<TreeNode*> q({root});
        pq.push(root->val);
        
        int j, sz, levels = 0;
        long long sum;
        TreeNode *curr;
        
        while(!q.empty()) {
            levels++;
            sz = q.size();
            sum = 0;
            
            for(j = 0; j < sz; j++) {
                // iterate through level
                curr = q.front();
                q.pop();
                
                if(curr->left) {
                    sum += curr->left->val;
                    q.push(curr->left);
                }
                
                if(curr->right) {
                    sum += curr->right->val;
                    q.push(curr->right);   
                }
            }
            
            pq.push(sum);
        }
        
        if(levels < k) return -1;
        while(k > 1) {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};