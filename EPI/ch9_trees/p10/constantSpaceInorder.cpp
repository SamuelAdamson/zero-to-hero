#include <iostream>
#include <vector>
#include "tree/treeGenerator.hpp"

std::vector<int> inorder(std::shared_ptr<BinaryTreePNode<int>> root) {    
    std::vector<int> res;
    std::shared_ptr<BinaryTreePNode<int>> curr = root, prev = nullptr;

    while(curr) {
        if(curr->left && prev == curr->parent) {
            prev = curr;
            curr = curr->left;
        }
        else {
            if(prev != curr->right) res.push_back(curr->val);

            if(curr->right && (prev == curr->left || prev == curr->parent)) {
                prev = curr;
                curr = curr->right;
            }
            else {
                prev = curr;
                curr = curr->parent;
            }
        }
    }

    return res;
}

int main() {
    std::shared_ptr<BinaryTreePNode<int>> t1 = TreeGenerator::MakeBinaryTreeWithParentNodes({6,2,4,std::nullopt,11,2,5});
    std::shared_ptr<BinaryTreePNode<int>> t2 = TreeGenerator::MakeBinaryTreeWithParentNodes({6,2,4,13,11,2,5});
    std::shared_ptr<BinaryTreePNode<int>> t3 = TreeGenerator::MakeBinaryTreeWithParentNodes({314,6,6,271,561,2,271,28,0,std::nullopt,3,std::nullopt,1,std::nullopt,28});
    std::shared_ptr<BinaryTreePNode<int>> t4 = TreeGenerator::MakeBinaryTreeWithParentNodes({6,2,std::nullopt,8,11,std::nullopt,std::nullopt});

    auto r1 = inorder(t1);
    auto r2 = inorder(t2);
    auto r3 = inorder(t3);
    auto r4 = inorder(t4);

    for(int n : r1) std::cout << n << " ";
    std::cout << std::endl;
    
    for(int n : r2) std::cout << n << " ";
    std::cout << std::endl;

    for(int n : r3) std::cout << n << " ";
    std::cout << std::endl;

    for(int n : r4) std::cout << n << " ";
    std::cout << std::endl;
}