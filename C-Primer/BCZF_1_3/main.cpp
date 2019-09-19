//
//  main.cpp
//  BCZF_1_3
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool StringContain(string &a, string &b)
{
    int hash = 0;
    for (int i =0; i < a.size(); i++) {
        cout << (1 << (a[i] - 'A')) << endl;
        hash |= (1 << (a[i] - 'A'));
    }
    cout << hash << endl;
    for (int i = 0; i < b.size(); i ++) {
        cout << (1 << (b[i] - 'A')) << endl;
        cout << (hash & (1 << (b[i] - 'A'))) << endl;
                 
        if ((hash & (1 << (b[i] - 'A'))) == 0 ){
//            & 运算，只有 1-1 才回变成 1
            cout << "Not " << endl;
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string a = "ABCDK";
    string b = "ABE";
    cout << StringContain(a, b);
    
    return 0;
}
