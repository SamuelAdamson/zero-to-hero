#include <iostream>
#include <vector>
#include <queue>
#include "tree/treeGenerator.hpp"

std::shared_ptr<BinaryTreeNode<int>> reconstruct(const std::vector<std::optional<int>> &preorder) {
    if(preorder.empty() || !preorder[0]) return nullptr;

    std::shared_ptr<BinaryTreeNode<int>> curr, root = 
        std::make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>({preorder[0].value(), nullptr, nullptr}));
    std::queue<std::shared_ptr<BinaryTreeNode<int>>> q({root});

    int k, i = 1;
    while(i < preorder.size()) {
        k = i + 2 * q.size();

        while(i < k) {
            curr = q.front();
            q.pop();

            if(curr) {
                if(preorder[i])
                    curr->left = std::make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>({preorder[i].value(), nullptr, nullptr}));

                if(preorder[i+1])
                    curr->right = std::make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>({preorder[i+1].value(), nullptr, nullptr}));

                q.push(curr->left);
                q.push(curr->right);
            }
            else {
                q.push(nullptr);
                q.push(nullptr);
            }

            i += 2;
        }
    }

    return root;
}


// OUTPUT
void inorder(std::shared_ptr<BinaryTreeNode<int>> root) {
    if(!root) return;

    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

int main() {
    std::vector<std::optional<int>> t1 = {6,2,4,std::nullopt,11,2,5};
    std::vector<std::optional<int>> t2 = {6,2,4,7,11,2,5};
    std::vector<std::optional<int>> t3 = {6,std::nullopt,4,std::nullopt,std::nullopt,2,5,std::nullopt,std::nullopt,std::nullopt,std::nullopt,8,19,std::nullopt,7};

    auto r1 = reconstruct(t1);
    auto r2 = reconstruct(t2);
    auto r3 = reconstruct(t3);

    inorder(r1);
    std::cout << std::endl;

    inorder(r2);
    std::cout << std::endl;
        
    inorder(r3);
    std::cout << std::endl;
}