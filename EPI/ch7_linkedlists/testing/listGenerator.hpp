#include "node/node.hpp"
#include "node/doubleNode.hpp"
#include <vector>

#ifndef LISTGENERATOR_H
#define LISTGENERATOR_H

class ListGenerator {
public :

    static std::shared_ptr<Node<int>> ListGenerator::makeList(std::vector<int> v) {
        auto head = std::make_shared<Node<int>>();
        auto crawl = head;

        for(int n : v) {
            crawl->data = n;
            
            auto node = std::make_shared<Node<int>>();
            crawl->next = node;

            crawl = crawl->next;
        }

        return head;
    }

    static std::shared_ptr<DoubleNode<int>> ListGenerator::makeDoubleList(std::vector<int> v) {
        auto head = std::make_shared<DoubleNode<int>>();
        auto crawl = head;

        for(int n : v) {
            crawl->data = n;

            auto node = std::make_shared<DoubleNode<int>>();
            node->last = crawl;
            crawl->next = node;

            crawl = crawl->next;
        }

        return head;
    }
};

#endif