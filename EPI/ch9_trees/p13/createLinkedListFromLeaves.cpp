#include <iostream>
#include <vector>
#include "tree/treeGenerator.hpp"
#include "ch7_linkedlists/node/node.hpp"

void helper(std::shared_ptr<BinaryTreeNode<int>> t, std::shared_ptr<ListNode<int>> &l) {
    if(!t->left && !t->right)  {
        l->next = std::make_shared<ListNode<int>>(ListNode<int>({t->val, nullptr}));
        l = l->next;
    }
    else {
        if(t->left) 
            helper(t->left, l);
        
        if(t->right)
            helper(t->right, l);
    }
}

std::shared_ptr<ListNode<int>> getList(std::shared_ptr<BinaryTreeNode<int>> root) {
    if(!root) return nullptr;

    std::shared_ptr<ListNode<int>> dh = std::make_shared<ListNode<int>>(ListNode<int>({0, nullptr}));
    std::shared_ptr<ListNode<int>> curr = dh;
    
    helper(root, curr);
    return dh->next;
}


// OUTPUT
void crawl(std::shared_ptr<ListNode<int>> h) {
    while(h) {
        std::cout << h->data << " ";
        h = h->next;
    }
    std::cout << std::endl;
}

int main() {
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({6,2,4,13,11,2,5});
    std::shared_ptr<BinaryTreeNode<int>> t2 = TreeGenerator::MakeBinaryTree({6,2,4,std::nullopt,11,2,5});
    std::shared_ptr<BinaryTreeNode<int>> t3 = TreeGenerator::MakeBinaryTree({6,3,4,12,7,std::nullopt,16,std::nullopt,std::nullopt,8,std::nullopt,std::nullopt,std::nullopt,std::nullopt,9});

    std::shared_ptr<ListNode<int>> r1 = getList(t1);
    std::shared_ptr<ListNode<int>> r2 = getList(t2);
    std::shared_ptr<ListNode<int>> r3 = getList(t3);

    crawl(r1);
    crawl(r2);
    crawl(r3);
}