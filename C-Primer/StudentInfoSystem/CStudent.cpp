//
//  CStudent.cpp
//  StudentInfoSystem
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include "CStudent.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

CStudent::CStudent(){
    this->id = -1;
}
CStudent::~CStudent(){}

int CStudent::getID() const {return id;}
void CStudent::setID(int val) {id = val;}

string CStudent::getName() const{ return name;}
void CStudent::setName(string val){name = val;}

int CStudent::getAge()const{return age;}
void CStudent::setAge(int val) {
    age = val;
}


std::ostream & operator << (std::ostream & os, CStudent &stu)
{
    os << stu.getID()<< "   " << stu.getName() << "   " <<stu.getAge();
    return os;
}

std::istream & operator>>(std::istream & is, CStudent & stu) {
    is>>stu.id>>stu.name>>stu.age;
    return is;
}
