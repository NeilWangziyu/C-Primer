//
//  main.cpp
//  JZ5
//
//  Created by 王子昱 on 2019/7/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

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
    
    
    return 0;
}
