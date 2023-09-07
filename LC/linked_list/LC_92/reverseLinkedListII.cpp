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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dh = new ListNode(0, head), *prev = dh;
        int i = 1;

        while(i < left){
            prev = prev->next;
            i++;
        }

        ListNode *s = prev, *c, *temp;
        prev = prev->next;
        c = prev->next;

        while(i < right) {
            temp = c->next;
            c->next = prev;
            prev = c;
            c = temp;
            i++;
        }

        s->next->next = c;
        s->next = prev;

        return dh->next;
    }
};
