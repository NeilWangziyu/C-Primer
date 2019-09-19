//
//  main.cpp
//  BCZF_1_5
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(const string input)
{
    if (input.size() <= 1) {
        return true;
    }
    int front = 0;
    int back = input.size()-1;
    while (front <= back) {
        if (input[front] == input[back]) {
            front += 1;
            back -= 1;
        }
        else
            return false;
    }
    return true;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    string s = "aba";
    
    cout <<  IsPalindrome(s) << endl;
    cout << IsPalindrome("aaaaav") << endl;
    return 0;
}
