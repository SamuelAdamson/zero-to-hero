/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(
        vector<Node*> &nodeMap,
        vector<bool> &visited,
        Node* curr
    ) {
        for(Node* node : curr->neighbors) {
            if(!visited[node->val]) {
                visited[node->val] = true;
                nodeMap[node->val] = new Node(node->val);

                dfs(nodeMap, visited, node);
            }

            nodeMap[curr->val]->neighbors.push_back(nodeMap[node->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        vector<Node*> nodeMap(101);
        vector<bool> visited(101);

        visited[node->val] = true;
        nodeMap[node->val] = new Node(node->val);

        dfs(nodeMap, visited, node);
        return nodeMap[node->val];
    }
};