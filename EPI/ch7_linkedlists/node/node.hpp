#include <memory>

template <typename T>
struct ListNode {
    T data;

    // Using shared pointers here, because we are allowing
    //  for multiple nodes to point to the same node
    std::shared_ptr<ListNode<T>> next;    
};
