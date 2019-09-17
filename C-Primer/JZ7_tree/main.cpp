//
//  main.cpp
//  JZ7_tree
//
//  Created by 王子昱 on 2019/9/17.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* constructcore(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 1) {
        BinaryTreeNode* res = new BinaryTreeNode();
        res->m_nValue = preorder[0];
        return res;
    }
    
    int first_num = preorder[0];
    
    int index = 0;
    while (inorder[index] != first_num) {
        index += 1;
    }
    std::vector<int> left_inorder = std::vector<int>(inorder.begin(), inorder.begin()+index);
    std::vector<int> right_inorder = std::vector<int>(inorder.begin()+index+1, inorder.end());
    
    int size_left = left_inorder.size();
    int size_right = right_inorder.size();
    
    
    std::vector<int> left_preorder = std::vector<int>(preorder.begin() + 1, preorder.begin() + 1 + size_left);
    std::vector<int> right_preorder = std::vector<int>(preorder.begin() + 1 + size_left, preorder.end());
    
    
    BinaryTreeNode *res = new BinaryTreeNode();
    res->m_nValue = first_num;
    
    if (size_right != 0) {
        res->m_pLeft = constructcore(left_preorder, left_inorder);
    }
    if (size_right != 0) {
        
        res->m_pRight = constructcore(right_preorder, right_inorder);
    }
    return res;
    
}

BinaryTreeNode* construct(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0 || inorder.size() == 0) {
        return nullptr;
    }
    return constructcore(preorder, inorder);
}

void PrintTree(BinaryTreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    
    cout << root -> m_nValue << endl;
    
    if (root->m_pLeft != nullptr) {
        PrintTree(root->m_pLeft);
    }
    if (root->m_pRight != nullptr) {
        PrintTree(root->m_pRight);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> preorder = {1,2, 4, 7, 3, 5, 6, 8};
    vector<int> inorder = {4,7,2, 1, 5, 3, 8, 6};
    
    BinaryTreeNode* res = construct(preorder, inorder);
    
    PrintTree(res);
    
    return 0;
}
