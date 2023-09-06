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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        vector<ListNode*> result(k);

        ListNode* c = head, *temp;
        while(c) {
            n++;
            c = c->next;
        }

        int s = n / k, r = n % k, i, j;
        for(i = 0, c = head; i < k && c; i++) {
            result[i] = c;
            for(j = 1; j < s + (r > 0) && c; j++)
                c = c->next;

            r--;
            if(c) {
                temp = c->next;
                c->next = nullptr;
                c = temp;
            }
        }

        return result;
    }
};
