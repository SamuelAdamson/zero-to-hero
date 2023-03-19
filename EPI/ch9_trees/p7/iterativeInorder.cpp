#include <iostream>
#include <stack>
#include "tree/treeGenerator.hpp"

struct Node {
    std::shared_ptr<BinaryTreeNode<int>> node;
    bool leftVisited;
};

std::vector<int> inorder(std::shared_ptr<BinaryTreeNode<int>> root) {
    std::vector<int> res;
    std::stack<Node> s({{root, false}});
    
    while(!s.empty()) {
        if(s.top().node == nullptr) s.pop();
        else {
            if(s.top().leftVisited) {
                Node r = {s.top().node->right, false};
                res.push_back(s.top().node->val);
                s.pop();
                s.push(r);
            }
            else {
                s.top().leftVisited = true;
                s.push({s.top().node->left, false});
            }
        }
    }

    return res;
}


int main() {
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({6,2,4,std::nullopt,11,2,5});
    std::shared_ptr<BinaryTreeNode<int>> t2 = TreeGenerator::MakeBinaryTree({6,2,4,13,11,2,5});
    std::shared_ptr<BinaryTreeNode<int>> t3 = TreeGenerator::MakeBinaryTree({314,6,6,271,561,2,271,28,0,std::nullopt,3,std::nullopt,1,std::nullopt,28});

    std::vector<int> r1 = inorder(t1);
    std::vector<int> r2 = inorder(t2);
    std::vector<int> r3 = inorder(t3);

    for(int n : r1) std::cout << n << " ";
    std::cout << std::endl;

    for(int n : r2) std::cout << n << " ";
    std::cout << std::endl;

    for(int n : r3) std::cout << n << " ";
    std::cout << std::endl;
}