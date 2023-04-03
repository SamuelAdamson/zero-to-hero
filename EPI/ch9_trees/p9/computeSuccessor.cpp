#include <iostream>
#include "tree/treeGenerator.hpp"

std::shared_ptr<BinaryTreePNode<int>> leftmost(std::shared_ptr<BinaryTreePNode<int>> node) {
    if(node->left) return leftmost(node->left);
    return node;
}

std::shared_ptr<BinaryTreePNode<int>> helper(std::shared_ptr<BinaryTreePNode<int>> curr, std::shared_ptr<BinaryTreePNode<int>> prev) {
    if(!curr) return nullptr;

    if(curr->left == prev) return curr;
    if(curr->right == prev) return helper(curr->parent, curr);
    
    return curr->right ? leftmost(curr->right) : nullptr;
}

std::shared_ptr<BinaryTreePNode<int>> findSuccessor(std::shared_ptr<BinaryTreePNode<int>> node) {
    if(node->right) return leftmost(node->right);
    return helper(node->parent, node);
}
