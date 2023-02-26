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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prev = NULL, *slow = NULL, *fast = head;
        int offset = 1, sz = 0;
        
        while(fast != NULL) {
            fast = fast->next;
            prev = slow;
            
            if(offset >= n) {
                if(offset == n) slow = head;
                else slow = slow->next;
            }
            
            sz++;
            offset++;
        }
        
        if(sz != n) prev->next = slow->next;
        else head = head = head->next; 
            
        return head;
    }
};