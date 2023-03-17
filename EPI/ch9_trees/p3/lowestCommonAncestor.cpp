#include <iostream>
#include "tree/treeGenerator.hpp"

struct status {
    std::shared_ptr<BinaryTreeNode<int>> node;
    int nodesFound;
};

status helper(
    std::shared_ptr<BinaryTreeNode<int>> root,
    int n1, int n2
) {
    if(!root) return {nullptr, 0};
    int found = 0;

    status sl = helper(root->left, n1, n2); 
    if(sl.nodesFound == 2) return sl;

    status sr = helper(root->right, n1, n2);
    if(sr.nodesFound == 2) return sr;

    found += sl.nodesFound + sr.nodesFound;
    found += root->val == n1 || root->val == n2;

    return {root, found};
}

std::shared_ptr<BinaryTreeNode<int>> lca(
    std::shared_ptr<BinaryTreeNode<int>> root,
    int n1, int n2
) {
    return helper(root, n1, n2).node;
}

int main() {
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({2,5,3,6,7,8,9});

    std::cout << lca(t1, 6, 7)->val << std::endl;
}