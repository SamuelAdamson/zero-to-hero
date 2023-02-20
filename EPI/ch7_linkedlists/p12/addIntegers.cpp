#include <iostream>
#include "testing/listGenerator.hpp"


std::shared_ptr<ListNode<int>> add(std::shared_ptr<ListNode<int>> l1, std::shared_ptr<ListNode<int>> l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    std::shared_ptr<ListNode<int>> h = l1;
    int sum = l1->data + l2->data, digit;

    l1->data = sum % 10;
    sum /= 10;
    
    while(sum || l1->next || l2->next) {
        if(l1->next) sum += l1->next->data;
        if(l2->next) sum += l2->next->data;

        digit = sum % 10;
        sum /= 10;

        if(l1->next) l1->next->data = digit;
        else l1->next = std::make_shared<ListNode<int>>(ListNode<int>({digit, nullptr}));
        
        l1 = l1->next;
        if(l2->next) l2 = l2->next;
    }

    return h;
}


int main() {
    // Test cases
    std::shared_ptr<ListNode<int>> t1_1 = ListGenerator::makeList({3, 1, 4});
    std::shared_ptr<ListNode<int>> t1_2 = ListGenerator::makeList({7, 0, 9});

    std::shared_ptr<ListNode<int>> t2_1 = ListGenerator::makeList({3});
    std::shared_ptr<ListNode<int>> t2_2 = ListGenerator::makeList({7});

    std::shared_ptr<ListNode<int>> r1 = add(t1_1, t1_2);
    std::shared_ptr<ListNode<int>> r1 = add(t2_1, t2_2);

    while(r1) {
        std::cout << r1->data;
        r1 = r1->next;
    }
    std::cout << std::endl;

    while(r2) {
        std::cout << r2->data;
        r2 = r2->next;
    }
    std::cout << std::endl;
}