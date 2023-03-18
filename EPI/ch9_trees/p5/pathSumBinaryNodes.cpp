#include <iostream>
#include "tree/treeGenerator.hpp"

int helper(std::shared_ptr<BinaryTreeNode<int>> root, int curr) {
    curr <<= 1;
    curr |= root->val; // assuming each value is a 0 or 1

    if(!root->left && !root->right) return curr;
    
    int sum = 0;
    if(root->left) sum += helper(root->left, curr);
    if(root->right) sum += helper(root->right, curr); 
    
    return sum;
}

int sum(std::shared_ptr<BinaryTreeNode<int>> root) {
    if(!root) return 0;
    return helper(root, 0);
}

int main() {
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({1,0,1,0,1,0,0,0,1,std::nullopt,1,std::nullopt,0,std::nullopt,0});

    std::cout << sum(t1) << std::endl;
}