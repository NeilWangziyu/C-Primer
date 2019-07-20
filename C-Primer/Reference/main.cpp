//
//  main.cpp
//  Reference
//
//  Created by 王子昱 on 2019/7/20.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int &x, int& y);

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
double & setValues(int i)
{
    return vals[i];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int i;
    double d;
    int & r = i;
    double & s = d;
    
    i = 5;
    cout << "value of i: " << i <<endl;
    cout << "value of i reference : " << r <<endl;
    d = 11.7;
    cout << "value of d: " << d <<endl;
    cout << "value of d reference :" << s << endl;
    
    int a = 100;
    int b = 200;
    cout << a << " " << b<<endl;
    
    swap(a, b);
    cout << a << " " << b<<endl;
    
    cout << endl;
    cout << "before:" << endl;
    for (int index=0; index < 5; index++) {
        cout << "vals[" << index << "] = "<<vals[index] << endl;
        
    }
    setValues(1) = 11.11;
    setValues(3) = 70.9;
    //返回一个引用，然后对这个引用复赋值
    cout << "after" << endl;
    for (int index=0; index < 5; index++) {
        cout << "vals[" << index << "] = "<<vals[index] << endl;
        
    }

    
    return 0;
}

void swap(int &x, int&y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    return ;
}

//菜单：-> Editor -> Structure ->Re-Indent
//自动排版
