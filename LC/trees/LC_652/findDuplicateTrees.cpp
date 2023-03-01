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
    string serialize(TreeNode *root, unordered_map<string, vector<TreeNode*>> &m) {
        if(!root) return "";
        
        string s = "("+serialize(root->left, m)+","+serialize(root->right, m)+","+to_string(root->val)+")";
        m[s].push_back(root);

        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> subtrees;
        vector<TreeNode*> result;

        serialize(root, subtrees);

        for(auto subtree : subtrees)
            if(subtree.second.size() > 1) result.push_back(subtree.second[0]);

        return result;
    }
};