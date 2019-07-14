//
//  main.cpp
//  JZ3
//
//  Created by 王子昱 on 2019/7/13.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length < 0)
        return false;
    for (int i=0; i<length; i++) {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    
    for (int i =0; i < length; i ++) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            //swap
            int temp = numbers[i] ;
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
    
}

int countRange(const int* numbers, int length, int start, int end)
{
    if (numbers == nullptr) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= start && numbers[i] <= end) {
            ++count;
        }
    }
    return count;
}




int GetDuplication(const int* numbers, int length)
{
    if (numbers == nullptr || length <=0) {
        return -1;
    }
    
    int start = 1;
    int end = length - 1;
    while (end >= start) {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if (end == start) {
            if (count > 1) {
                return start;
            }else
                break;
        }
        if (count > (middle -start +1)) {
            end = middle;
        }
        else
            start = middle + 1;
    }
    return -1;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
