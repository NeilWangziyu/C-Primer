//
//  Header.h
//  C-Primer
//
//  Created by 王子昱 on 2019/7/13.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator = (const CMyString &str);
    
    
private:
    char* m_pData;
};


#endif /* Header_h */
