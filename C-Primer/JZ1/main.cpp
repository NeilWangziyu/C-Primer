//
//  main.cpp
//  JZ1
//
//  Created by 王子昱 on 2019/7/13.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include "Header.h"

CMyString& CMyString::operator = (const CMyString &str)
{
    if(this==&str)
        return *this;
    delete []m_pData;
    m_pData = nullptr;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;

}

//CMyString& CMyString::operator=(const CMyString &str)
//{
//    if(this != &str)
//    {
//        CMyString strTemp(str);
//        char *pTemp = strTemp.m_pData;
//        strTemp.m_pData = m_pData;
//        m_pData = pTemp;
//    }
//    return *this;
//
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    // I dont know how to use it
    
    
    return 0;
}
