#include "tree/binaryTreeNode.hpp"
#include <vector>
#include <queue>

#ifndef TREEGENERATOR_H
#define TREEGENERATOR_H

class TreeGenerator {
public :

    static std::unique_ptr<BinaryTreeNode<int>> GenerateBinaryTree(std::vector<std::unique_ptr<BinaryTreeNode<int>>> &nodes) {
        if(nodes.empty()) return nullptr;
        
        int levelSize = 1, i, k;
        std::queue<std::unique_ptr<BinaryTreeNode<int>>> q;
        q.push(nodes[0]);

        for(i = 1; i < nodes.size(); i++) {
            


        }
    
    }


};

#endif