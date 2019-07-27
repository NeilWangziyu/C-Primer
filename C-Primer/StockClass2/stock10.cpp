//
//  stock10.cpp
//  StockClass2
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include "stock10.hpp"
#include <iostream>

Stock::Stock()
{
    std::cout << "Default construction" << std::endl;
    company = "no name";
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock(const std::string &co, long n , double pr)
{
    std::cout << "Another construction" << std::endl;
    company = co;
    if (n < 0) {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0." << std::endl;
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();

}

Stock::~Stock()
{
    std::cout << "bye" << std::endl;
}


void Stock::buy(long num, double price)
{
    if (num < 0) {
        std::cout <<" Number of shares purchased cant be negative " << " Transaction is aborted " << std::endl;
    }
    else{
        shares += num;
        share_val = price;
        set_tot();
        
    }
    
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0) {
        cout << "Number of shares sold cant be negative" << std::endl;
    }
    else if (num > shares)
    {
        cout << "can not sell more than you have" << std::endl;
    }
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company : " << company << " shares : " << shares << std::endl;
    cout << " Share price : $" << share_val << std::endl;
    cout.precision(2);
    cout << " Total worth: $ "<< total_val << "\n";
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val) {
        return s;
    }else
        return *this;
}
