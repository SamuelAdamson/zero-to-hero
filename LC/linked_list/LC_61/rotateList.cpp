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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *c = head, *nh = nullptr;
        int n = 0;

        while(c) {
            c = c->next;
            n++;
        }

        if(!n || !(k % n)) return head;
        k %= n;

        c = head;
        for(n = n-k-1; n > 0; n--) c = c->next;
        nh = c->next;
        c->next = nullptr;

        c = nh;
        while(c->next) c = c->next;
        c->next = head;

        return nh;
    }
};