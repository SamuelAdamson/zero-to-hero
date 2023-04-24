#include "binaryTreeNode.hpp"
#include "binaryTreePNode.hpp"
#include "binaryTreeNNode.hpp"
#include "binaryTreeXNode.hpp"
#include <vector>
#include <queue>
#include <optional>

#ifndef TREEGENERATOR_H
#define TREEGENERATOR_H

class TreeGenerator {
private :

    static unsigned CountNodes(std::shared_ptr<BinaryTreeNNode<int>> root) {
        if(!root) return 0;
        root->n = 1;

        root->n += CountNodes(root->left);
        root->n += CountNodes(root->right);

        return root->n;
    }


public :

    static std::shared_ptr<BinaryTreeNode<int>> MakeBinaryTree(const std::vector<std::optional<int>> &preorder) {
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

    static std::shared_ptr<BinaryTreePNode<int>> MakeBinaryTreeWithParentNodes(const std::vector<std::optional<int>> &preorder) {
        if(preorder.empty() || !preorder[0]) return nullptr;

        std::shared_ptr<BinaryTreePNode<int>> curr, root = 
            std::make_shared<BinaryTreePNode<int>>(BinaryTreePNode<int>({preorder[0].value(), nullptr, nullptr, nullptr}));
        std::queue<std::shared_ptr<BinaryTreePNode<int>>> q({root});

        int k, i = 1;
        while(i < preorder.size()) {
            k = i + 2 * q.size();

            while(i < k) {
                curr = q.front();
                q.pop();

                if(curr) {
                    if(preorder[i])
                        curr->left = std::make_shared<BinaryTreePNode<int>>(BinaryTreePNode<int>({preorder[i].value(), nullptr, nullptr, curr}));

                    if(preorder[i+1])
                        curr->right = std::make_shared<BinaryTreePNode<int>>(BinaryTreePNode<int>({preorder[i+1].value(), nullptr, nullptr, curr}));

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

    static std::shared_ptr<BinaryTreeNNode<int>> MakeBinaryTreeWithNumNodes(const std::vector<std::optional<int>> &preorder) {
        if(preorder.empty() || !preorder[0]) return nullptr;

        std::shared_ptr<BinaryTreeNNode<int>> curr, root = 
            std::make_shared<BinaryTreeNNode<int>>(BinaryTreeNNode<int>({preorder[0].value(), 0, nullptr, nullptr}));
        std::queue<std::shared_ptr<BinaryTreeNNode<int>>> q({root});

        int k, i = 1;
        while(i < preorder.size()) {
            k = i + 2 * q.size();

            while(i < k) {
                curr = q.front();
                q.pop();

                if(curr) {
                    if(preorder[i])
                        curr->left = std::make_shared<BinaryTreeNNode<int>>(BinaryTreeNNode<int>({preorder[i].value(), 0, nullptr, nullptr}));

                    if(preorder[i+1])
                        curr->right = std::make_shared<BinaryTreeNNode<int>>(BinaryTreeNNode<int>({preorder[i+1].value(), 0, nullptr, nullptr}));

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

        CountNodes(root);
        return root;
    }

    // Note: This does NOT establish the relationship between next nodes
    static std::shared_ptr<BinaryTreeXNode<int>> MakeBinaryTreeWithNextNode(const std::vector<std::optional<int>> &preorder) {
        if(preorder.empty() || !preorder[0]) return nullptr;

        std::shared_ptr<BinaryTreeXNode<int>> curr, root = 
            std::make_shared<BinaryTreeXNode<int>>(BinaryTreeXNode<int>({preorder[0].value(), nullptr, nullptr, nullptr}));
        std::queue<std::shared_ptr<BinaryTreeXNode<int>>> q({root});

        int k, i = 1;
        while(i < preorder.size()) {
            k = i + 2 * q.size();

            while(i < k) {
                curr = q.front();
                q.pop();

                if(curr) {
                    if(preorder[i])
                        curr->left = std::make_shared<BinaryTreeXNode<int>>(BinaryTreeXNode<int>({preorder[i].value(), nullptr, nullptr, nullptr}));

                    if(preorder[i+1])
                        curr->right = std::make_shared<BinaryTreeXNode<int>>(BinaryTreeXNode<int>({preorder[i+1].value(), nullptr, nullptr, nullptr}));

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

};

#endif