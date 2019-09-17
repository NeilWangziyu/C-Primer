//
//  main.cpp
//  JZ5
//
//  Created by 王子昱 on 2019/7/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
void ReplaceBlank(char string[], int length)
{
    if (string == nullptr || length <= 0) {
        return;
    }
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0') {
        ++ originalLength;
        if (string[i] == ' ') {
            ++numberOfBlank;
        }
        ++i;
    }
    
    int newLength = originalLength + numberOfBlank*2;
    
    cout << "newLength: " << newLength << endl;
    if (newLength > length) {
        return;
    }
    
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfOriginal > indexOfOriginal) {
        if (string[indexOfOriginal] == ' ') {
            string[indexOfNew -- ] = '0';
            string[indexOfNew -- ] = '2';
            string[indexOfNew -- ] = '%';

        }
        else{
            string[indexOfNew --] = string[indexOfNew];
        }
        -- indexOfOriginal;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    char input[14] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'd', '\0'};
    cout << sizeof(input) << endl;;
    ReplaceBlank(input, 11);
    cout << input  << endl;
    
    
    return 0;
}
