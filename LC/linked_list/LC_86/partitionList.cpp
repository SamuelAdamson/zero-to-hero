/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dh1, dh2;
        ListNode *s = &dh1, *g = &dh2, *c = head;

        while(c != nullptr) {
            if(c->val < x) {
                s->next = c;
                s = s->next;
            }
            else {
                g->next = c;
                g = g->next;
            }

            c = c->next;
        }
        
        g->next = nullptr;
        s->next = dh2.next;

        return dh1.next;
    }
};