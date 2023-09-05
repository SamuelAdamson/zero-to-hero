/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *nh = new Node(head->val);
        unordered_map<Node*, Node*> m; // original list node : new list node

        Node *c1 = head, *c2 = nh;
        m[c1] = c2;

        while(c1->next) {
            c1 = c1->next;
            c2->next = new Node(c1->val);
            c2 = c2->next;

            m[c1] = c2;
        }

        c1 = head, c2 = nh;
        while(c1) {
            c2->random = m[c1->random];
            c1 = c1->next;
            c2 = c2->next;
        }

        return nh;
    }
};