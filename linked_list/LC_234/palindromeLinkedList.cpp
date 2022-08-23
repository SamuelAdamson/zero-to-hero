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
    bool isPalindrome(ListNode* head) {
        /*  Check if a singly linked list is palindromic
        
            Traverse the entire linked list to get the length of list.
            Then, traverse to the middle of the linked list, along the way,
            reverse the first half of the list. 
            
            Then hold two pointers one for the first half (reversed), and one
            for the second half. Traverse simultaneously checking each value.
        */
        int n = 0;
        ListNode *crawl = head, *rightCrawl = head, *temp;
        bool palindrome = true;
        
        while(crawl != NULL) {
            n++;
            crawl = crawl->next;
        }
        
        for(int i = 0; i < n/2; i++) {
            temp = rightCrawl->next;
            rightCrawl->next = crawl;
            crawl = rightCrawl;
            rightCrawl = temp;
        }
        
        if(n % 2) rightCrawl = rightCrawl->next;
        for(int i = 0; i < n/2 && palindrome; i++) {
            if(crawl->val != rightCrawl->val) palindrome = 0;
            crawl = crawl->next;
            rightCrawl = rightCrawl->next;
        }
        
        return palindrome;
    }
};