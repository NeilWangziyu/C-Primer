//
//  main.cpp
//  purevirtual
//
//  Created by 王子昱 on 2019/7/6.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

#include "Header.h"

using namespace std;


double Bulk_quota::net_price (size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discont) * price;
    else
        return cnt * price;
}

void Bulk_quota::print()
{
    Quota::print();
    cout << "quantity: " << quantity << " discont: " << discont << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Bulk_quota bulk("iSBN for bulk", 15, 9, 0.8);
    
    bulk.print();
    
    return 0;
}
