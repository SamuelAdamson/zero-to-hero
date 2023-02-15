#include <iostream>
#include "testing/listGenerator.hpp"


std::shared_ptr<ListNode<int>> overlapping(std::shared_ptr<ListNode<int>> h1, std::shared_ptr<ListNode<int>> h2) {
    int m = 1, n = 1;
    std::shared_ptr<ListNode<int>> c1 = h1, c2 = h2;

    while(c1->next) {
        c1 = c1->next;
        m++;
    }

    while(c2->next) {
        c2 = c2->next;
        n++;
    }

    // There is no overlap if not equal
    if(c1 != c2) return nullptr;

    while(m > n) {
        h1 = h1->next;
        m--;
    }

    while(n > m) {
        h2 = h2->next;
        n--;
    }

    while(h1 && h2 && h1 != h2) h1 = h1->next, h2 = h2->next;
    return h1;
}


// Verify solution with book, test cases are pretty lengthy here
//      and are not really the primary goal of these exercises