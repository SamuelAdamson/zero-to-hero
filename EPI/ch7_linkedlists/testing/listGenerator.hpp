#include "node/node.hpp"
#include "node/doubleNode.hpp"
#include <vector>

#ifndef LISTGENERATOR_H
#define LISTGENERATOR_H

class ListGenerator {
public :

    static std::shared_ptr<ListNode<int>> makeList(std::vector<int> v) {
        auto dummyHead = std::make_shared<ListNode<int>>();
        auto crawl = dummyHead;

        for(int n : v) {
            auto node = std::make_shared<ListNode<int>>();
            node->data = n;
            
            crawl->next = node;
            crawl = crawl->next;
        }

        return dummyHead->next;
    }

    static std::shared_ptr<DoubleNode<int>> makeDoubleList(std::vector<int> v) {
        auto dummyHead = std::make_shared<DoubleNode<int>>();
        auto crawl = dummyHead;

        for(int i = 0; i < v.size(); i++) {
            auto node = std::make_shared<DoubleNode<int>>();
            node->data = v[i];
            
            if(i) node->last = crawl;
            crawl->next = node;
            crawl = crawl->next;
        }

        return dummyHead->next;
    }
};

#endif