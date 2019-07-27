//
//  CStudent.hpp
//  StudentInfoSystem
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef CStudent_hpp
#define CStudent_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class CStudent
{
    friend std::ostream & operator << (std::ostream &os, CStudent &std);
    friend std::istream & operator >> (std::istream &is, CStudent &stu);
public:
    CStudent();
    ~CStudent();
    
    int getID() const;
    void setID(int val);
    std::string getName() const;
    void setName(std::string val);
    
    int getAge() const;
    void setAge(int val);
    
private:
    int id;
    std::string name;
    int age;
};




#endif /* CStudent_hpp */
