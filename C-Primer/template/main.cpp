//
//  main.cpp
//  template
//
//  Created by 王子昱 on 2019/7/20.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;
template <typename T>
inline T const& Max(T const&a, T const &b)
{
    return a < b ? b:a;
}

template <class T>
class Stack{
private:
    vector<T> elems;
    
public:
    void push(T const &);
    void pop();
    T top() const;
    bool empty() const{
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const& elem){
    elems.push_back(elem);
}


template <class T>
void Stack<T>::pop()
{
    if (this->empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (this->empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    return elems.back();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int i = 39;
    int j = 20;
    
    cout << "max(i, j) is " << Max(i, j) << endl;
    
    double f1 = 13.5;
    double f2 = 11.5;
    cout << Max(f1, f2) << endl;
    
    try {
        Stack<int> intStack;
        Stack<string> stringStack;
        intStack.push(7);
        cout << intStack.top() << endl;
        
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
        
    } catch (exception const& ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
    
    
    return 0;
}
