#include "binaryTreeNode.hpp"
#include "binaryTreePNode.hpp"
#include <vector>
#include <queue>
#include <optional>

#ifndef TREEGENERATOR_H
#define TREEGENERATOR_H

class TreeGenerator {
public :

    static std::shared_ptr<BinaryTreeNode<int>> MakeBinaryTree(const std::vector<std::optional<int>> &v) {
        if(v.empty()) return nullptr;

        std::shared_ptr<BinaryTreeNode<int>> curr;
        std::shared_ptr<BinaryTreeNode<int>> h = !v[0] ? nullptr : std::make_shared<BinaryTreeNode<int>>(
            BinaryTreeNode<int>({v[0].value(), nullptr, nullptr})
        );
        std::queue<std::shared_ptr<BinaryTreeNode<int>>> q({h});

        for(int i = 1; i < v.size(); i += 2) {
            curr = q.front();
            q.pop();

            if(!curr) continue;    
            curr->left = v[i] ? std::make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>({v[i].value(), nullptr, nullptr})) : nullptr;
            curr->right = v[i+1] ? std::make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>({v[i+1].value(), nullptr, nullptr})) : nullptr;;

            q.push(curr->left);
            q.push(curr->right);
        }

        return h;
    }

    static std::shared_ptr<BinaryTreePNode<int>> MakeBinaryTreeWithParentNodes(const std::vector<std::optional<int>> &v) {
        if(v.empty()) return nullptr;

        std::shared_ptr<BinaryTreePNode<int>> curr;
        std::shared_ptr<BinaryTreePNode<int>> h = !v[0] ? nullptr : std::make_shared<BinaryTreePNode<int>>(
            BinaryTreePNode<int>({v[0].value(), nullptr, nullptr})
        );
        std::queue<std::shared_ptr<BinaryTreePNode<int>>> q({h});

        for(int i = 1; i < v.size(); i += 2) {
            curr = q.front();
            q.pop();

            if(!curr) continue;    
            curr->left = v[i] ? std::make_shared<BinaryTreePNode<int>>(BinaryTreePNode<int>({v[i].value(), nullptr, nullptr, curr})) : nullptr;
            curr->right = v[i+1] ? std::make_shared<BinaryTreePNode<int>>(BinaryTreePNode<int>({v[i+1].value(), nullptr, nullptr, curr})) : nullptr;;

            q.push(curr->left);
            q.push(curr->right);
        }

        return h;
    }

};

#endif