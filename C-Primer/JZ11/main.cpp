//
//  main.cpp
//  JZ11
//
//  Created by 王子昱 on 2019/9/17.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int MinInOrder(vector<int> arr, int startIndex, int endIndex)
{
    int res = arr[startIndex];
    for (int i = startIndex + 1; i <= endIndex; i ++) {
        res = max(res, arr[i]);
    }
    return res;
}

int Min(vector<int> arr)
{
    if (arr.size() == 0) {
        return -1;
    }
    int index1 = 0;
    int index2 = arr.size() - 1;
    int indexmid = index1;
//   if arr[index1] < arr[index2], means it is in order, so, return arr[0]
    while (arr[index1] >= arr[index2]) {
        if (index2 - index1 == 1) {
            indexmid = index2;
            break;
        }
        indexmid = (index1 + index2) / 2;
        
        if (arr[index1] == arr[index2] && arr[index2] == arr[indexmid]) {
            return MinInOrder(arr, index1, index2);
        }
        if (arr[indexmid] >= arr[index1]) {
            index1 = indexmid;
        }
        else if(arr[indexmid] <= arr[index2])
        {
            index2 = indexmid;
        }
    }
    return arr[indexmid];
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> input = {3,4,5,0,1,2};
    int res = Min(input);
    cout << res << endl;
    
    
    return 0;
}
