class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int sz, k;
        bool leafFound = false;

        TreeNode *curr;
        queue<TreeNode*> q({root});

        while(!q.empty()) {
            sz = q.size();

            for(k = 0; k < sz; k++) {
                curr = q.front();
                q.pop();

                if(curr->left) {
                    if(leafFound) return false;
                    q.push(curr->left);
                }
                else leafFound = true;
                
                if(curr->right) {
                    if(leafFound) return false;
                    q.push(curr->right);
                }
                else leafFound = true;
            }
        }

        return true;
    }
};