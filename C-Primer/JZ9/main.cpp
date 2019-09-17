//
//  main.cpp
//  JZ9
//
//  Created by 王子昱 on 2019/9/17.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;
template <typename T>
class CQueue {
private:
    stack<T> stack1;
    stack<T> stack2;
    
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T& node);
    T deleteHead();
};

template<typename T>
void CQueue<T>::appendTail(const T & element)
{
    stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead() {
    if (stack2.size() <= 0) {
        while (stack1.size() > 0) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    
    if (stack2.size() == 0) {
        throw new invalid_argument("queue is empty");
    }
    T head = stack2.top();
    stack2.pop();
    return head;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    CQueue<int> ourqueue;
    
    ourqueue.appendTail(10);
    ourqueue.appendTail(11);
    ourqueue.appendTail(12);
    
    cout << ourqueue.deleteHead() << endl;
    cout << ourqueue.deleteHead() << endl;
    cout << ourqueue.deleteHead() << endl;

    return 0;
}
