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
    ListNode *merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head, *crawl;
        
        if(l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        
        crawl = head;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                crawl->next = l1;
                l1 = l1->next;
            }
            else {
                crawl->next = l2;
                l2 = l2->next;
            }
            
            crawl = crawl->next;
        }
        
        if(l1 != NULL) crawl->next = l1;
        if(l2 != NULL) crawl->next = l2;
        
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head, *temp;
        
        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        
        
        return merge(l1, l2);
    }
};