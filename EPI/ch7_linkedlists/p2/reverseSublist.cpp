#include <iostream>
#include "testing/listGenerator.hpp"

 
std::shared_ptr<ListNode<int>> reverseSublist(std::shared_ptr<ListNode<int>> h, int s, int f) {
    // Note that the list is 1-indexed
    int i;

    std::shared_ptr<ListNode<int>> dummy = std::make_shared<ListNode<int>>(ListNode<int>{0, h});
    std::shared_ptr<ListNode<int>> anchor = dummy, fast, temp;

    for(i = 1; i < s; i++) {
        h = h->next;
        anchor = anchor->next;
    }

    fast = h->next;
    for(i = i + 1; i <= f; i++) {
        temp = fast->next;
        fast->next = h;

        h = fast;
        fast = temp;
    }

    anchor->next->next = fast;
    anchor->next = h;

    return dummy->next;
}


int main() {
    // Test cases
    std::shared_ptr<ListNode<int>> t1 = ListGenerator::makeList({11, 7, 5, 3, 2});
    int t1_s = 2, t1_f = 4;

    std::shared_ptr<ListNode<int>> t2 = ListGenerator::makeList({11, 7});
    int t2_s = 1, t2_f = 2;

    std::shared_ptr r1 = reverseSublist(t1, t1_s, t1_f);
    std::shared_ptr r2 = reverseSublist(t2, t2_s, t2_f);

    while(r1) {
        std::cout << r1->data << " ";
        r1 = r1->next;
    }
    std::cout << std::endl;

    while(r2) {
        std::cout << r2->data << " ";
        r2 = r2->next;
    }
    std::cout << std::endl;
}