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
private:
    const int MOD_VAL = int(1e9 + 7);
    typedef unsigned long long ull;
    
    ull best, sum, sub;
    
public:
    ull treeSum(TreeNode* root) {
        if(root == NULL) return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }
    
    ull dfs(TreeNode* root) {
        if(root == NULL) return 0;
        sub = root->val + dfs(root->left) + dfs(root->right);
        
        ull prod = sub * (sum - sub);
        if(prod > best) best = prod;
            
        return sub;
    }
    
    int maxProduct(TreeNode* root) {
        sum = treeSum(root), best = 0, sub = 0;
        dfs(root);
        return best % MOD_VAL;
    }
};