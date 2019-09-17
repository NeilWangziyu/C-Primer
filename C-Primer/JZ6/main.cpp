//
//  main.cpp
//  JZ6
//
//  Created by 王子昱 on 2019/9/17.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void PrintListReveringly_I(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    
    while (!nodes.empty()) {
        pNode = nodes.top();
        std::cout << pNode->m_nValue << std::endl;
        nodes.pop();
    }
    
}

void PrintListReveringly_R(ListNode* pHead)
{
    if (pHead != nullptr) {
        if (pHead->m_pNext != nullptr) {
            PrintListReveringly_R(pHead->m_pNext);
        }
        std::cout << pHead->m_nValue << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ListNode root = {1};
    ListNode r1 = {2};
    ListNode r2 = {3};
    root.m_pNext = &r1;
    r1.m_pNext = &r2;
    ListNode* r = &root;
    PrintListReveringly_I(r);
    
    PrintListReveringly_R(r);
    
    return 0;
}
