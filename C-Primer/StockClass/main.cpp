//
//  main.cpp
//  StockClass
//
//  Created by 王子昱 on 2019/7/27.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include "stock00.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Stock kate = Stock("Microsoft", 50, 5.5);
//    kate.acquire("Microsoft", 50, 5.5);
    kate.show();
    kate.buy(100, 5.0);
    kate.show();
    
    Stock jot = Stock("Apple", 120, 11);
//    jot.acquire("Apple", 120, 11);
    jot.show();
    
    return 0;
}
