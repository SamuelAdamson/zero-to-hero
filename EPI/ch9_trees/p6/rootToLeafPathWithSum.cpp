#include <iostream>
#include "tree/treeGenerator.hpp"

bool helper(std::shared_ptr<BinaryTreeNode<int>> root, int curr, int target) {
    curr += root->val;
    if(!root->left && !root->right) return curr == target;

    return (root->left != nullptr && helper(root->left, curr, target)) ||
           (root->right != nullptr && helper(root->right, curr, target));
}

bool hasPathSum(std::shared_ptr<BinaryTreeNode<int>> root, int sum) {
    if(!root) return false;
    return helper(root, 0, sum);
}


int main() {
    std::pair<std::shared_ptr<BinaryTreeNode<int>>, int> t1 = {TreeGenerator::MakeBinaryTree({6,2,4,std::nullopt,11,2,5}), 12};
    std::pair<std::shared_ptr<BinaryTreeNode<int>>, int> t2 = {TreeGenerator::MakeBinaryTree({6,2,4,std::nullopt,11,2,5}), 19};
    std::pair<std::shared_ptr<BinaryTreeNode<int>>, int> t3 = {TreeGenerator::MakeBinaryTree({6,2,4,std::nullopt,11,2,5}), 8};

    std::cout << hasPathSum(t1.first, t1.second) << std::endl;
    std::cout << hasPathSum(t2.first, t2.second) << std::endl;
    std::cout << hasPathSum(t3.first, t3.second) << std::endl;
}