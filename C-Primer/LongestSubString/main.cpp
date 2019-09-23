//
//  main.cpp
//  LongestSubString
//
//  Created by 王子昱 on 2019/9/23.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int LongestSubString(vector<int> arr)
{
    int len = arr.size();
    if (len <2) {
        return len;
    }
    vector<int> dp(len, 1);
    for (int i = 0; i < len; i ++) {
        for (int j = 0; j < i; j ++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int max_len = 0;
    for (int item:dp) {
        max_len = max(max_len, item);
    }
    return max_len;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> arr = {10,22,9,33,21,50,41,60,80};
    int res = LongestSubString(arr);
    cout << res ;
    

    return 0;
}
