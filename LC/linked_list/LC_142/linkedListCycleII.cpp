/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;

        do {
            fast = fast->next->next;
            slow = slow->next;
        } while(fast && fast->next && slow != fast);
        if(slow != fast) return NULL;

        // get cycle length
        int cycle = 1;
        fast = fast->next;

        while(fast != slow) {
            fast = fast->next;
            cycle++;
        }

        // offset fast by cycle length
        slow = fast = head;
        while(cycle > 0) {
            fast = fast->next;
            cycle--;
        }

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};