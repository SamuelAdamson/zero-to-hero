#include <memory>

/* This binary tree node stores the number of nodes in this subtree */

template <typename T>
struct BinaryTreeNNode {
    T val;
    unsigned n;

    std::shared_ptr<BinaryTreeNNode<int>> left;
    std::shared_ptr<BinaryTreeNNode<int>> right;
};