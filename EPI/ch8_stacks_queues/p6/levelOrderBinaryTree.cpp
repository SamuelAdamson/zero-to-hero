#include <iostream>
#include <queue>
#include <vector>
#include <optional>
#include "tree/treeGenerator.hpp"

std::vector<std::vector<int>> levelOrderTree(std::shared_ptr<BinaryTreeNode<int>> h) {
    std::vector<std::vector<int>> result;
    if(!h) return result;
    
    int k, sz;
    std::queue<std::shared_ptr<BinaryTreeNode<int>>> q({h});
    std::shared_ptr<BinaryTreeNode<int>> curr;

    while(!q.empty()) {
        std::vector<int> row;
        sz = q.size();

        for(k = 0; k < sz; k++) {
            curr = q.front();
            q.pop();

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            row.push_back(curr->val);
        }

        result.push_back(row);
    }

    return result;
}


int main() {
    // Test cases
    std::shared_ptr<BinaryTreeNode<int>> t1 = TreeGenerator::MakeBinaryTree({1, 2, 3, 9, 4, 5, 12});
    std::shared_ptr<BinaryTreeNode<int>> t2 = TreeGenerator::MakeBinaryTree({1, std::nullopt, 2, std::nullopt, std::nullopt, 13, std::nullopt});

    std::vector<std::vector<int>> r1 = levelOrderTree(t1);
    std::vector<std::vector<int>> r2 = levelOrderTree(t2);
    
    for(int i = 0; i < r1.size(); i++) {
        for(int n : r1[i]) std::cout << n << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < r2.size(); i++) {
        for(int n : r2[i]) std::cout << n << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}