//
//  main.cpp
//  JZ4
//
//  Created by 王子昱 on 2019/7/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
bool Find(int *matrix, int rows, int columns, int number)
{
    // 从右上角开始选择
    //
    bool found = false;
    if(matrix != nullptr && rows > 0 && columns >0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            if(matrix[row*columns+column]==number)
            {
                found = true;
                break;
            }else if(matrix[row*columns+column] > number)
                --column;
            else
                ++row;
        }
    }
    return found;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
