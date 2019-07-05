//
//  main.cpp
//  virtualFunction
//
//  Created by 王子昱 on 2019/7/5.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
using namespace std;

class A
{
public:
    virtual void foo()
    {
        cout << "A::foo() is called" << endl;
        
    }
};

class B : public A
{
    void foo()
    {
        cout << "B::foo is called" << endl;
    }
};


//　纯虚函数是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。
// 在基类中实现纯虚函数的方法是在函数原型后加“=0”



int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    A *a = new B();
    a -> foo();
    // 在这里，a虽然是指向A的指针，但是被调用的函数(foo)却是B的!
//  这个例子是虚函数的一个典型应用，通过这个例子，也许你就对虚函数有了一些概念。它虚就虚在所谓“推迟联编”或者“动态联编”上，一个类函数的调用并不是在编译时刻被确定的，而是在运行时刻被确定的。由于编写代码的时候并不能确定被调用的是基类的函数还是哪个派生类的函数，所以被成为“虚”函数。

    return 0;
}
/*
1、纯虚函数声明如下： virtual void funtion1()=0; 纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。包含纯虚函数的类是抽象类，抽象类不能定义实例，但可以声明指向实现该抽象类的具体类的指针或引用。
2、虚函数声明如下：virtual ReturnType FunctionName(Parameter)；虚函数必须实现，如果不实现，编译器将报错，错误提示为：
error LNK****: unresolved external symbol "public: virtual void __thiscall ClassName::virtualFunctionName(void)"
3、对于虚函数来说，父类和子类都有各自的版本。由多态方式调用的时候动态绑定。
4、实现了纯虚函数的子类，该纯虚函数在子类中就编程了虚函数，子类的子类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。
5、虚函数是C++中用于实现多态(polymorphism)的机制。核心理念就是通过基类访问派生类定义的函数。
6、在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的。
7、友元不是成员函数，只有成员函数才可以是虚拟的，因此友元不能是虚拟函数。但可以通过让友元函数调用虚拟成员函数来解决友元的虚拟问题。
8、析构函数应当是虚函数，将调用相应对象类型的析构函数，因此，如果指针指向的是子类对象，将调用子类的析构函数，然后自动调用基类的析构函数。
*/
