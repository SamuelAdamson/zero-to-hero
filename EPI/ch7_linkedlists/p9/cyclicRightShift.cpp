#include <iostream>
#include "testing/listGenerator.hpp"

std::shared_ptr<ListNode<int>> cyclicRightShift(std::shared_ptr<ListNode<int>> h, int k) {
    std::shared_ptr<ListNode<int>> dh = std::make_shared<ListNode<int>>(ListNode<int>{0, h});
    std::shared_ptr<ListNode<int>> last = h;

    // get size check k in bounds
    int n = 1, i;
    while(last->next) {
        last = last->next;
        n++;
    }

    // new k value (protection for k > n)
    k %= n;
    if(!k) return h;

    for(i = 1; i < (n - k); i++) h = h->next;
    
    last->next = dh->next;
    dh->next = h->next;
    h->next = nullptr;

    return dh->next;
}

int main() {
    // Test cases
    std::pair<std::shared_ptr<ListNode<int>>, int> t1 = { ListGenerator::makeList({1, 2, 3, 4, 5}), 2 };
    std::pair<std::shared_ptr<ListNode<int>>, int> t2 = { ListGenerator::makeList({1, 2, 3, 4, 5}), 5 };
    std::pair<std::shared_ptr<ListNode<int>>, int> t3 = { ListGenerator::makeList({1, 2, 3, 4, 5}), 214 };

    std::shared_ptr<ListNode<int>> r1 = cyclicRightShift(t1.first, t1.second);
    std::shared_ptr<ListNode<int>> r2 = cyclicRightShift(t2.first, t2.second);
    std::shared_ptr<ListNode<int>> r3 = cyclicRightShift(t3.first, t3.second);

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