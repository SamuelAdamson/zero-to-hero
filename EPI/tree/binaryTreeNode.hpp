#include <memory>

template <typename T>
struct BinaryTreeNode {
    T val;

    std::unique_ptr<BinaryTreeNode<int>> left;
    std::unique_ptr<BinaryTreeNode<int>> right;
};
