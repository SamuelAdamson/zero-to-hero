#include <memory>

template <typename T>
struct BinaryTreeNode {
    T val;

    std::shared_ptr<BinaryTreeNode<int>> left;
    std::shared_ptr<BinaryTreeNode<int>> right;
};
