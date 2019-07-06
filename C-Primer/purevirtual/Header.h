//
//  Header.h
//  C-Primer
//
//  Created by 王子昱 on 2019/7/6.
//  Copyright © 2019 王子昱. All rights reserved.
//


#ifndef Header_h
#define Header_h

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
    
    virtual void print()
    {
        cout << "bookNo:" << bookNo << endl;
    }
    
private:
    string bookNo;
    
protected:
    double price = 0.0;
};


class Disc_quota:public Quota{
public:
    Disc_quota() = default;
    Disc_quota(const string &book, double price, size_t qty, double disc):
    Quota(book, price), quantity(qty), discont(disc) {}
    
    double net_price(size_t) const = 0;
    // the net_price function is a pure virtual function
    
    
    
protected:
    size_t quantity = 0;
    double discont = 0.0;
};

class Bulk_quota : public Disc_quota
{
public:
    
    Bulk_quota() = default;
    Bulk_quota (const string &book, double price, size_t qty, double disc):
    Disc_quota(book, price, qty, disc) {}
    
    double net_price(size_t) const override;
    
    void print() override;
    
};

#endif /* Header_h */
