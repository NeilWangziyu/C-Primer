//
//  main.cpp
//  NK_1
//
//  Created by 王子昱 on 2019/9/21.
//  Copyright © 2019 王子昱. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    for(int index = 0; index <n ;index ++)
    {
        int num;
        cin >> num;
        vector<int> check_list(num, 0);
        int total_sum=0;
        for(int each = 0; each < num ; each ++)
        {
            //            这个地方，有一点问题
            cin >> check_list[each];
        }
        
        sort(check_list.begin(), check_list.end());
        vector<vector<int>> dp(num/2+1, vector<int>(total_sum/2+1,0));
        
        dp[0][0] = 1;
        
        // for i in range(min(k, num//2), 0, -1):
        for(int k =0; k < num;k++)
        {
            for(int i = min(k, num/2);i > 0;i--)
            {
                for(int j=0;j<total_sum/2+1;j++)
                {
                    if (j >= check_list[k] && dp[i - 1][j - check_list[k]]==1)
                        dp[i][j] = 1;
                }
            }
        }
        for(int e = total_sum / 2;e >= 0;e--)
        {
            if(dp[num/2][e]==1)
            {
                cout << e << total_sum - e <<endl;
                break;
            }
        }
    }
}
