#include <iostream>
#include "testing/listGenerator.hpp"

std::shared_ptr<ListNode<int>> evenOddMerge(std::shared_ptr<ListNode<int>> h) {
    // all even indices at start of list (0-indexed)
    // all odds following
    if(!h || !h->next) return h;

    std::shared_ptr<ListNode<int>> fe = h, fo = h->next, lo = h->next;
    std::shared_ptr<ListNode<int>> le = lo->next;

    // while the last even is not null
    while(lo && le) {
        fe->next = le;
        lo->next = le->next;
        le->next = fo;
        
        // move iterators
        fe = fe->next;
        lo = lo->next;

        if(lo) le = lo->next;
    }

    return h;
}

int main() {
    // Test cases
    std::shared_ptr<ListNode<int>> t1 = ListGenerator::makeList({0, 1, 2, 3, 4, 5});
    std::shared_ptr<ListNode<int>> t2 = ListGenerator::makeList({0, 1, 2, 3, 4});
    std::shared_ptr<ListNode<int>> t3 = ListGenerator::makeList({0, 1, 2});
    std::shared_ptr<ListNode<int>> t4 = ListGenerator::makeList({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    std::shared_ptr<ListNode<int>> r1 = evenOddMerge(t1);
    std::shared_ptr<ListNode<int>> r2 = evenOddMerge(t2);
    std::shared_ptr<ListNode<int>> r3 = evenOddMerge(t3);
    std::shared_ptr<ListNode<int>> r4 = evenOddMerge(t4);

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

    while(r3) {
        std::cout << r3->data << " ";
        r3 = r3->next;
    }
    std::cout << std::endl;

    while(r4) {
        std::cout << r4->data << " ";
        r4 = r4->next;
    }
    std::cout << std::endl;
}