#include <iostream>
#include <utility>
#include "tree/treeGenerator.hpp"

std::shared_ptr<BinaryTreeNNode<int>> getKthNode(std::shared_ptr<BinaryTreeNNode<int>> root, int k) {   
    if(!root || k > root->n) return nullptr;

    if(root->left) {
        unsigned l = root->left->n;
        if(k <= l) return getKthNode(root->left, k);

        k -= l;
    }

    
    if(--k == 0) return root;
    return getKthNode(root->right, k);
}

int main() {
    std::pair<std::shared_ptr<BinaryTreeNNode<int>>, int> t1 = {TreeGenerator::MakeBinaryTreeWithNumNodes({6,2,4,std::nullopt,11,2,5}), 2};
    std::pair<std::shared_ptr<BinaryTreeNNode<int>>, int> t2 = {TreeGenerator::MakeBinaryTreeWithNumNodes({6,2,4,std::nullopt,11,2,5}), 6};
    
    auto r1 = getKthNode(t1.first, t1.second);
    auto r2 = getKthNode(t2.first, t2.second);

    std::cout << r1->val << std::endl;
    std::cout << r2->val << std::endl;
}