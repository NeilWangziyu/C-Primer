//
//  stock10.hpp
//  StockClass2
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef stock10_hpp
#define stock10_hpp

#include <stdio.h>
#include <string>

class Stock{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot()
    {
        total_val = shares * share_val;
    }
public:
    Stock();
    Stock(const std::string &co, long n = 0, double pr =0.0);
    ~Stock();
//    init is important
    
    void buy(long num, double price);
    void sell(long num, double prive);
    void update(double price);
    void show();
    const Stock & topval(const Stock & s) const;
};




#endif /* stock10_hpp */
