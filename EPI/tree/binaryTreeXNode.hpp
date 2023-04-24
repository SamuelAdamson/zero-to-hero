#include <memory>

/* This binary tree node stores next rightmost node */

template <typename T>
struct BinaryTreeXNode {
    T val;

    // next right node
    std::shared_ptr<BinaryTreeXNode<T>> next;

    std::shared_ptr<BinaryTreeXNode<T>> left;
    std::shared_ptr<BinaryTreeXNode<T>> right;
};