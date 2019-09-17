//
//  main.cpp
//  JZ10
//
//  Created by 王子昱 on 2019/9/17.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

long long Fibonacci0(unsigned int n)
{
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return Fibonacci0(n - 1) + Fibonacci0(n - 2);
}

long long Fibonacci(unsigned int n)
{
    int result[2] = {0, 1};
    if (n < 2) {
        return result[n];
    }
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    
    for (unsigned int i = 2; i <= n; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::cout << Fibonacci(15) << std::endl;
    std::cout << Fibonacci0(15) << std::endl;

    
    return 0;
}
