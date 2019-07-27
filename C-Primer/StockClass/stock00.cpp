//
//  stock00.cpp
//  StockClass
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "stock00.h"



void Stock::acquire(const std::string &co, long n, double pr)
{
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

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show(){
    std::cout << "Company: " << company << " shares: " << shares << " \n" << " Share price : $ " << share_val << " Total Worth : $" << total_val << std::endl;
    
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
