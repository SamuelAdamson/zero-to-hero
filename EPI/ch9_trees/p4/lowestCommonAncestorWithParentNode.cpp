#include <iostream>
#include "tree/treeGenerator.hpp"

struct Node {
    int distance;
    std::shared_ptr<BinaryTreePNode<int>> node;
};


Node findNode(std::shared_ptr<BinaryTreePNode<int>> root, int n) {
    if(!root) return {-1, nullptr};
    if(root->val == n) return {0, root};

    Node l = findNode(root->left, n);
    if(l.node) return {l.distance + 1, l.node};

    Node r = findNode(root->right, n);
    if(r.node) return {r.distance + 1, r.node};

    return {-1, nullptr};
}

std::shared_ptr<BinaryTreePNode<int>> lca(std::shared_ptr<BinaryTreePNode<int>> root, int n1, int n2) {
    Node a = findNode(root, n1);
    std::shared_ptr<BinaryTreePNode<int>> ca = a.node;

    Node b = findNode(root, n2);
    std::shared_ptr<BinaryTreePNode<int>> cb = b.node;

    for(int i = a.distance; i > b.distance; i--)
        ca = ca->parent;

    for(int i = b.distance; i > a.distance; i--)
        cb = cb->parent;

    while(ca != cb) {
        ca = ca->parent;
        cb = cb->parent;
    }

    return ca;
}


int main() {
    std::shared_ptr<BinaryTreePNode<int>> t1 = TreeGenerator::MakeBinaryTreeWithParentNodes({2,5,3,6,7,8,9});

    std::cout << lca(t1, 8, 9)->val << std::endl;
    std::cout << lca(t1, 5, 9)->val << std::endl;
}