#include <iostream>
#include "testing/listGenerator.hpp"


bool isPalindrome(std::shared_ptr<ListNode<int>> h) {
    if(!h || !h->next) return true;

    int n = 0, i, even;
    std::shared_ptr<ListNode<int>> r = h, l = h, pre, curr;

    // get length of list
    while(r) {
        r = r->next;
        n++;
    }
    even = !(n & 1);

    // iterate list in tandem, reversing as we go
    pre = nullptr;
    r = even ? h->next : h->next->next;
    for(i = 0; i < n/2 - 1; i++) {
        curr = l;

        r = r->next;
        l = l->next;

        curr->next = pre;
        pre = curr;
    }
    
    // iterate both directions from center, checking values
    l->next = pre;

    while(l && r) {
        if(l->data != r->data) return false;
        l = l->next;
        r = r->next;
    }

    return true;
}


int main() {
    // Test cases
    std::shared_ptr<ListNode<int>> t1 = ListGenerator::makeList({0, 1, 2, 2, 1, 0});
    std::shared_ptr<ListNode<int>> t2 = ListGenerator::makeList({7, 12, 2, 12, 7});
    std::shared_ptr<ListNode<int>> t3 = ListGenerator::makeList({0, 1, 2, 1, 1});
    std::shared_ptr<ListNode<int>> t4 = ListGenerator::makeList({0});
    std::shared_ptr<ListNode<int>> t5 = ListGenerator::makeList({0, 1});

    std::cout << isPalindrome(t1) << std::endl;
    std::cout << isPalindrome(t2) << std::endl;
    std::cout << isPalindrome(t3) << std::endl;
    std::cout << isPalindrome(t4) << std::endl;
    std::cout << isPalindrome(t5) << std::endl;
}