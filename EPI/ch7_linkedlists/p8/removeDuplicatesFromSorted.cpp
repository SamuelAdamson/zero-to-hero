#include <iostream>
#include "testing/listGenerator.hpp"


std::shared_ptr<ListNode<int>> removeDuplicatesFromSorted(std::shared_ptr<ListNode<int>> h) {
    int n = h->data;
    std::shared_ptr<ListNode<int>> anchor = h, crawl = h->next;

    while(crawl) {
        if(crawl->data != n) {
            n = crawl->data;
            anchor->next = crawl;
            anchor = crawl;
        }

        crawl = crawl->next;
    }

    if(anchor->next) anchor->next = nullptr;
    return h;
}


int main() {
    // Test cases
    std::shared_ptr<ListNode<int>> t1 = ListGenerator::makeList({2,2,3,5,5,5,7,7,11,11,11});
    std::shared_ptr<ListNode<int>> t2 = ListGenerator::makeList({1,1,2,2,2,2,2,2,2,2,2,2,3});
    std::shared_ptr<ListNode<int>> t3 = ListGenerator::makeList({1,1});
    
    std::shared_ptr<ListNode<int>> r1 = removeDuplicatesFromSorted(t1);
    std::shared_ptr<ListNode<int>> r2 = removeDuplicatesFromSorted(t2);
    std::shared_ptr<ListNode<int>> r3 = removeDuplicatesFromSorted(t3);

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
}