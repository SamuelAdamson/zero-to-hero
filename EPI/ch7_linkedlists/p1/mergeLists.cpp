#include <iostream>
#include "testing/listGenerator.hpp"

std::shared_ptr<ListNode<int>> mergeLists(std::shared_ptr<ListNode<int>> l1, std::shared_ptr<ListNode<int>> l2) {
    std::shared_ptr<ListNode<int>> dummyHead(new ListNode<int>);
    std::shared_ptr<ListNode<int>> crawl = dummyHead;

    while(l1 && l2) {
        if(l1->data <= l2->data){
            crawl->next = l1;
            l1 = l1->next;
        } 
        else {
            crawl->next = l2;
            l2 = l2->next;
        }

        crawl = crawl->next;
    }

    if(l1) crawl->next = l1;
    if(l2) crawl->next = l2;

    return dummyHead->next;
}


int main() {
    // Test cases
    auto h1 = ListGenerator::makeList({1, 2, 5, 7});
    auto h2 = ListGenerator::makeList({3, 11});

    auto h3 = ListGenerator::makeList({});
    auto h4 = ListGenerator::makeList({1000});

    std::shared_ptr<ListNode<int>> r1 = mergeLists(h1, h2);
    std::shared_ptr<ListNode<int>> r2 = mergeLists(h3, h4);

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