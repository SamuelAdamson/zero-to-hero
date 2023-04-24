#include <iostream>
#include <vector>
#include "tree/treeGenerator.hpp"


void left(std::shared_ptr<BinaryTreeNode<int>> root, std::vector<int> &res) {
    if(!root || !(root->left || root->right)) return;

    res.push_back(root->val);
    
    if(root->left)
        left(root->left, res);
    else
        left(root->right, res);
}

void bottom(std::shared_ptr<BinaryTreeNode<int>> root, std::vector<int> &res) {
    if(!root->left && !root->right) res.push_back(root->val);
    else {
        if(root->left) bottom(root->left, res);
        if(root->right) bottom(root->right, res);
    }
}

void right(std::shared_ptr<BinaryTreeNode<int>> root, std::vector<int> &res) {
    if(!root || !(root->left || root->right)) return;

    if(root->right)
        right(root->right, res);
    else
        right(root->left, res);

    res.push_back(root->val);
}


std::vector<int> exterior(std::shared_ptr<BinaryTreeNode<int>> root) {
    std::vector<int> res;

    if(root) {
        res.push_back(root->val);

        left(root->left, res);
        bottom(root, res);
        right(root->right, res);
    }

    return res;
}


int main() {
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({6,2,4,13,11,2,5});
    std::shared_ptr<BinaryTreeNode<int>> t2 = TreeGenerator::MakeBinaryTree({6,2,4,std::nullopt,11,2,5});
    std::shared_ptr<BinaryTreeNode<int>> t3 = TreeGenerator::MakeBinaryTree({6,3,4,12,7,std::nullopt,16,std::nullopt,std::nullopt,8,std::nullopt,std::nullopt,std::nullopt,std::nullopt,9});
    std::shared_ptr<BinaryTreeNode<int>> t4 = TreeGenerator::MakeBinaryTree({6,3,4,12,7,16,std::nullopt,std::nullopt,std::nullopt,8,std::nullopt,std::nullopt,9,std::nullopt,std::nullopt});

    std::vector<int> r1 = exterior(t1);
    std::vector<int> r2 = exterior(t2);
    std::vector<int> r3 = exterior(t3);

    for(int i : r1) std::cout << i << " ";
    std::cout << std::endl;

    for(int i : r2) std::cout << i << " ";
    std::cout << std::endl;

    for(int i : r3) std::cout << i << " ";
    std::cout << std::endl;
}