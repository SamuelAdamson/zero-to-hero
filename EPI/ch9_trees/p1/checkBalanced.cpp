#include <iostream>
#include "tree/treeGenerator.hpp"

int balanced(std::shared_ptr<BinaryTreeNode<int>> root) {
    if(!root) return 0;
    
    int l = balanced(root->left);
    if(l == -1) return -1;

    int r = balanced(root->right);
    if(r == -1) return -1;

    if(std::abs(l - r) > 1) return -1;
    return std::max(l, r) + 1;
}

bool isBalanced(std::shared_ptr<BinaryTreeNode<int>> root) {
    return balanced(root) != -1;
}

int main() {
    // Testing
    auto t1 = TreeGenerator::MakeBinaryTree({1, 2, 3, 4, std::nullopt, std::nullopt, std::nullopt}); // true
    auto t2 = TreeGenerator::MakeBinaryTree({1, std::nullopt, 3, std::nullopt, std::nullopt, 4, 5}); // false

    std::cout << isBalanced(t1) << std::endl;
    std::cout << isBalanced(t2) << std::endl;
}