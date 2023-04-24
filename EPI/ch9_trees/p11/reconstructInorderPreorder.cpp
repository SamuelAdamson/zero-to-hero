#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include "tree/treeGenerator.hpp"


std::shared_ptr<BinaryTreeNode<int>> helper(
    const std::vector<int> &inorder,
    const std::vector<int> &preorder,
    const std::unordered_map<int, int> &iMap,
    int &i, int l, int h, int n
) {
    int val = preorder[i++];
    int j = iMap[val], k;

    std::shared_ptr<BinaryTreeNode<int>> root = std::make_shared<BinaryTreeNode<int>>(
        BinaryTreeNode<int>({val, nullptr, nullptr}));

    do {
        if(i >= n) break;
        k = iMap.at(preorder[i]);

        if(k >= l && k < j) 
            root->left = helper(inorder, preorder, iMap, i, l, j-1, n);
        else if(k > j && k <= h) 
            root->right = helper(inorder, preorder, iMap, i, j+1, h, n);
    } while(k >= l && k <= h);

    return root;
}

std::shared_ptr<BinaryTreeNode<int>> reconstruct(const std::vector<int> &inorder, const std::vector<int> &preorder) {
    int n = inorder.size();
    if(n == 0) return nullptr;

    std::unordered_map<int, int> iMap;

    for(int i = 0; i < n; i++) 
        iMap[inorder[i]] = i;

    int i = 0;
    return helper(inorder, preorder, iMap, i, 0, n-1, n);
}


// OUTPUT
void inorder(std::shared_ptr<BinaryTreeNode<int>> root) {
    if(!root) return;

    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

int main() {
    std::pair<std::vector<int>, std::vector<int>> t1 = {
        {12, 3, 8, 7, 6, 4, 16, 9, 13},
        {6, 3, 12, 7, 8, 4, 16, 9, 13}
    };

    auto r1 = reconstruct(t1.first, t1.second);
    
    inorder(r1);
    std::cout << std::endl;
}