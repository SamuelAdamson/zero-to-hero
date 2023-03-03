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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, TreeNode*> graph; // map child to parent

        for(int i = 0; i < descriptions.size(); i++) {
            TreeNode *p = nodeMap[descriptions[i][0]];
            TreeNode *c = nodeMap[descriptions[i][1]];
            
            if(!c) {
                c = new TreeNode(descriptions[i][1]);
                nodeMap[descriptions[i][1]] = c;
            }

            if(!p) {
                p = new TreeNode(descriptions[i][0]);
                nodeMap[descriptions[i][0]] = p;
            }

            if(descriptions[i][2]) p->left = c;
            else p->right = c;
            
            graph[c->val] = p;
        }
        
        // traverse graph until we reach sink node (root)
        TreeNode *r = graph[descriptions[0][1]];

        while(graph.count(r->val))
            r = graph[r->val];

        return r;
    }
};