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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0, head);
        ListNode* last = &dummy;
        
        while(head != NULL) {
            if(head->next && head->val == head->next->val) {
                while(head->next && head->val == head->next->val) {
                    head = head->next;
                }
                last->next = head->next;
            }
            else {
                last = last->next;
            }
            head = head->next;
        }
        
        return dummy.next;
    }
};