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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 != NULL) return list2;
        else if(list1 != NULL && list2 == NULL) return list1;
        
        ListNode *head = NULL, *crawl = NULL;
        
        while(list1 != NULL && list2 != NULL) {    
            if(list1->val < list2->val) {
                if(head == NULL) head = list1, crawl = list1;
                else crawl->next = list1, crawl = crawl->next;
                
                list1 = list1->next;
            }
            else {
                if(head == NULL) head = list2, crawl = list2;
                else crawl->next = list2, crawl = crawl->next;
                
                list2 = list2->next;
            }
        }
        
        if(list1 != NULL && crawl != NULL) crawl->next = list1;
        if(list2 != NULL && crawl != NULL) crawl->next = list2; 
        
        return head;
    }
};