/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        /*  Level order traversal of a tree.
            
            Each node has an array of children. So, we can perform 
            a breadth-first style of traversal.
        */
        if(root == NULL) return {};
        vector<vector<int>> result ({{root->val}});
        queue<Node*> q({root});
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            
            for(int k = 0; k < sz; k++) {
                Node* front = q.front();
                q.pop();
                
                for(Node* child : front->children) {
                    level.push_back(child->val);
                    q.push(child);
                }
            }
            
            if(level.size() > 0) result.push_back(level);
        }
        
        return result;
    }
};