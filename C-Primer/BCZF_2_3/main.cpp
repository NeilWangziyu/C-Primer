//
//  main.cpp
//  BCZF_2_3
//
//  Created by 王子昱 on 2019/9/23.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//void SumOfNumCore(int sum, vector<vector<int>>& res, vector<int> arr)
//{
//    if (arr.size()==0) {
//        return;
//    }
//    if (sum == 0) {
//        res.push_back(arr);
//        return;
//    }
//    int tem = arr.back();
//    arr.pop_back();
//    SumOfNumCore(sum - tem, res, arr);
//    SumOfNumCore(sum, res, arr);
//}



//vector<vector<int>>& SumOfNum(int sum, vector<int> arr)
//{
//    void DFS(int sum, tem)
//    {}
//
//    vector<vector<int>> r;
//    vector<vector<int>>res = r;
//
//    DFS(sum, arr);
//    return res;
//}

int Max_Continue_Array(vector<int> arr)
{
    if (arr.size() == 0) {
        return 0;
    }
    int n = arr.size();
    int currSum = 0;
    int maxSum = arr[0];
    for (int j = 0; j < n; j++) {
        if (currSum >= 0) {
            currSum += arr[j];
        }
        else
        {
            currSum = arr[j];
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    vector<int> arr = {1,2,3,4,5,6,-1,7};
//    vector<vector<int>> res = SumOfNum(5, arr);
//    for (auto re:res) {
//        for (auto item:re) {
//            cout << item;
//        }
//        cout << endl;
//    }
//
    vector<int> arr = {1,2,3,4,5,6,-1,7};
    int res = Max_Continue_Array(arr);
    
    cout << res << endl;
    arr = {1, -2, 3, 10, -4, 7, 2, -5};
    res = Max_Continue_Array(arr);
    
    cout << res << endl;

    return 0;
}
