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
    ListNode* oddEvenList(ListNode* head) {
        if(head != NULL) {
            ListNode *og = head, *fast = head->next, *oldEven, *newOdd;
            
            while(fast != NULL && fast->next != NULL) {
                oldEven = og->next;
                newOdd = fast->next;
                
                fast->next = newOdd->next;
                og->next = newOdd;
                newOdd->next = oldEven;
                
                fast = fast->next;
                og = og->next;
            }
        }
        
        return head;
    }
};