#include <iostream>
#include "tree/treeGenerator.hpp"

bool helper(std::shared_ptr<BinaryTreeNode<int>> l, std::shared_ptr<BinaryTreeNode<int>> r) {
    if(!l && !r) return true;
    if(!l || !r) return false;

    return l->val == r->val && helper(l->left, r->right) && helper(l->right, r->left);
}

bool symmetric(std::shared_ptr<BinaryTreeNode<int>> root) {
    if(!root) return true;
    return helper(root->left, root->right);
}


int main() {
    // Test cases
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({2,3,3,std::nullopt,8,8,std::nullopt});
    std::shared_ptr<BinaryTreeNode<int>> t2 = TreeGenerator::MakeBinaryTree({2,3,3,std::nullopt,5,8,std::nullopt});
    std::shared_ptr<BinaryTreeNode<int>> t3 = TreeGenerator::MakeBinaryTree({2,3,3,6,8,8,6,12,std::nullopt,std::nullopt,5,5,std::nullopt,std::nullopt,12});

    std::cout << symmetric(t1) << std::endl;
    std::cout << symmetric(t2) << std::endl;
    std::cout << symmetric(t3) << std::endl;
}