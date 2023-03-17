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
    int pi;

    TreeNode *helper(
        const vector<int> &inorder,
        const vector<int> &postorder,
        unordered_map<int, int> &iMap,
        int s, int e
    ) {
        if(s > e) return nullptr;

        int val = postorder[pi--]; 
        TreeNode *root = new TreeNode(val);

        int i = iMap[val];

        root->right = helper(inorder, postorder, iMap, i+1, e);
        root->left = helper(inorder, postorder, iMap, s, i-1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size(), i;
        unordered_map<int, int> iMap;
        pi = n-1;
        
        for(i = 0; i < n; i++)
            iMap[inorder[i]] = i;      

        return helper(inorder, postorder, iMap, 0, n-1);
    }
};