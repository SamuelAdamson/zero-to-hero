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

    unordered_map<long long, int> prefix_map;

    int dfs(TreeNode *root, long long target, long long prefix) {
        if(!root) return 0;

        prefix += root->val;
        int paths = prefix_map[prefix - target];

        prefix_map[prefix]++;

        paths += dfs(root->left, target, prefix);
        paths += dfs(root->right, target, prefix); 

        prefix_map[prefix]--;
        
        return paths;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix_map[0] = 1;
        return dfs(root, (long long)targetSum, {});
    }
};

