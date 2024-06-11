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
    int pairSum(ListNode* head) {
        stack<int> s;
        int n = 0, result = 0;
        ListNode *c = head;

        while(c) {
            s.push(c->val);
            c = c->next;
        }

        c = head;

        while(n < s.size()) {
            result = max(result, s.top() + c->val);
            s.pop();
            n++;
            c = c->next;
        }

        return result;
    }
};

