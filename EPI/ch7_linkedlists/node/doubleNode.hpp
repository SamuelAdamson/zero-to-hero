#include <memory>

template <typename T>
struct DoubleNode {
    T data;

    // Using shared pointers here, because we are allowing
    //  for multiple nodes to point to the same node
    std::shared_ptr<DoubleNode<T>> next;
    std::shared_ptr<DoubleNode<T>> last;
};