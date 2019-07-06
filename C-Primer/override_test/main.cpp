//
//  main.cpp
//  override_test
//
//  Created by 王子昱 on 2019/7/6.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>

using namespace std;

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
    
};

struct D1 : B{
    void f1(int) const override;
    // f1都是const成员，接受一个int 返回 void
};

struct D2 : B{
    void f1(int) const final;
    //不允许后续的其他类覆盖f1
    
};

class base{
public:
    base() = default;
    
    base (string s)
    {
        basement = s;
    }
    
    string name() {return basement;}
    
    virtual void print(ostream &os)
    {
        os << basement << endl;;
    }
    
private:
    string  basement;
};

class derived : public base
{
public:
    derived() = default;
    
    derived (string s, int index) : base(s), i(index) {}
    
    
    void print(ostream &os)
    {
        base::print(os);
        os << " " << i << endl;
    }
private:
    int i;
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    base b("string for base");
    
    b.print(std::cout);
    
    derived d("stirng for derived", 10);
    
    d.print(std::cout);
    
    
    
    return 0;
}
