//
//  main.cpp
//  BCZF_1_3_0
//
//  Created by 王子昱 on 2019/9/19.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
bool CalAllpermutation(string perm, int num)
{
    int i;
    for (i = num - 2; i >= 0 && perm[i] >= perm[i+1]; --i) {
        ;
    }
    if (i < 0) {
        return false;
    }
    int k;
    for (k = num - 1; k > i && (perm[k] <= perm[i]); --k) {
        ;
    }
    cout << perm[i] << " " << perm[k] << endl;
    
    swap(perm[i], perm[k]);
    reverse(perm.begin() + i + 1, perm.end());
    
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    char inputs[6] = {'2','3','1','4','5','\0'};
    
//    char inputs[] = "23145";
//    char *perm;
//    perm = &inputs;
    string perm = "23541";
    
    CalAllpermutation(perm, perm.size());
    cout << perm << endl;
    cout << std::next_permutation(perm.begin(), perm.end()) << endl;
    cout << perm << endl;
    return 0;
}
