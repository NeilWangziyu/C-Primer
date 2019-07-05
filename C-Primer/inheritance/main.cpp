//
//  main.cpp
//  inheritance
//
//  Created by 王子昱 on 2019/7/5.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Quota{
public:
    Quota() = default;
    
    Quota(const string &book, double sales_price):
    bookNo(book), price(sales_price){ }
    
    string isbn() const {return bookNo;}
    
    
    virtual double net_price(size_t n) const {
        return n * price;
    }
//    size_t和unsigned int有所不同,size_t的取值range是目标平台下最大可能的数组尺寸
    
    virtual ~Quota() = default;
    
private:
    string bookNo;

protected:
    double price = 0.0;
};

class Bulk_quota:public Quota{
public:
    Bulk_quota() = default;

    Bulk_quota(const string& book,  double p , size_t qty, double disc):
    Quota(book, p), min_qty(qty), discont(disc){ }
    
//    double net_price(size_t) const override;
    double net_price(size_t cnt) const
    {
        if (cnt >= min_qty)
            return cnt * (1 - discont) * price;
        else
            return cnt * price;
    }
    //这个和上面一句声明不能在同一个文件里
    
private:
    size_t min_qty = 0;
    double discont = 0.0;
};

//动态绑定
double print_total(ostream &os, const Quota &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " <<item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Quota item("harry potter", 10);
    Bulk_quota bulk;
    Quota *p = &item;
    cout << item.net_price(56) <<endl;
    p = &bulk;
    Quota &r = bulk;
    // 派生到基类的类型转换
    return 0;
}
