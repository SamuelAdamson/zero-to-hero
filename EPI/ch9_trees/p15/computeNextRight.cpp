#include <iostream>
#include "tree/treeGenerator.hpp"

void helper(
    std::shared_ptr<BinaryTreeXNode<int>> l, 
    std::shared_ptr<BinaryTreeXNode<int>> r, 
    std::shared_ptr<BinaryTreeXNode<int>> parentRight
) {
    if(!l || !r) return;
    
    l->next = r;
    helper(l->left, l->right, r);

    if(parentRight) {
        r->next = parentRight->left;
        helper(r->left, r->right, parentRight->left);
    }
    else {
        helper(r->left, r->right, nullptr);
    }
}

// Note: assumption here is that the tree is perfect/complete
void addRightNodes(std::shared_ptr<BinaryTreeXNode<int>> root) {
    if(!root) return;

    root->next = nullptr;
    helper(root->left, root->right, nullptr);
}

// OUTPUT
void traverse(std::shared_ptr<BinaryTreeXNode<int>> root) {
    if(!root) return;

    std::cout << root->val << "(";
    if(root->next) std::cout << root->next->val;
    else std::cout << "null";
    std::cout << ")" << std::endl;

    traverse(root->left);
    traverse(root->right);
}

int main() {
    std::shared_ptr<BinaryTreeXNode<int>> t1 = TreeGenerator::MakeBinaryTreeWithNextNode({6,2,4,13,11,2,5});
    std::shared_ptr<BinaryTreeXNode<int>> t2 = TreeGenerator::MakeBinaryTreeWithNextNode({0, 1,2, 3,4,5,6, 7,8,9,10,11,12,13,14});
    std::shared_ptr<BinaryTreeXNode<int>> t3 = TreeGenerator::MakeBinaryTreeWithNextNode({0, 1,2, 3,4,5,6, 7,8,9,10,11,12,13,14, 15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30});

    addRightNodes(t1);
    addRightNodes(t2);
    addRightNodes(t3);

    traverse(t1);
    std::cout << std::endl;

    traverse(t2);
    std::cout << std::endl;

    traverse(t3);
}