#include <memory>

template <typename T>
struct BinaryTreePNode {
    T val;

    std::shared_ptr<BinaryTreePNode<int>> left;
    std::shared_ptr<BinaryTreePNode<int>> right;
    std::shared_ptr<BinaryTreePNode<int>> parent;
};