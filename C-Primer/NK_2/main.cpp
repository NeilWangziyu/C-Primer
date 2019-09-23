//
//  main.cpp
//  NK_2
//
//  Created by 王子昱 on 2019/9/22.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int N,M;
    cin >> N ;
    cin >> M;
    vector<int> Ai(N,0);
    
    for (int i = 0; i < N; i ++) {
        int x;
        cin >> x;
        Ai[i] = x;
    }
    
    for (int i = 0; i < M; i ++) {
        int t,x,prevt,prevx;
        cin >> t;
        cin >> x;
        
        if (prevx == 1) {
            continue;
        }
        
        if (t == 1) {
            if (prevt != 1 || (prevt==1 and x > prevx)) {
                sort(Ai.begin(), Ai.begin()+x);
                prevt = 1;
                prevx = x;
            }
            
        }
        else
            if (prevt != 2 || (prevt==2 and x > prevx)) {
                reverse(Ai.begin(), Ai.begin()+x);
                prevt = 2;
                prevx = x;
            }
    }
    for (auto item:Ai) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
