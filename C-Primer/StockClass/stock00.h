//
//  stock00.h
//  C-Primer
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#ifndef stock00_h
#define stock00_h

#include <string>
class Stock{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot(){
        total_val = shares * share_val;
    }
public:
    Stock(const std::string &co, long n, double pr)
    {
        if (n < 0) {
            std::cerr << "Number of shares can't be negative; " << company << " shares set to 0." << std::endl;
            shares = 0;
        }
        else
            shares = n;
        share_val = pr;
        set_tot();
    }
    ~Stock(){
        std::cout << "Bye Stock" << std::endl;
    };
    void acquire(const std::string & co, long n, double ptr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};



#endif /* stock00_h */
