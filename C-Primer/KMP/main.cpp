//
//  main.cpp
//  KMP
//
//  Created by 王子昱 on 2019/10/17.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getNext(string str)
    {
        int len = str.size();
        vector<int> next;
        next.push_back(-1);
        int j = 0, k = -1;
        while ( j < len - 1) {
            if(k==-1||str[j]==str[k])
            {
                j++;
                k++;
                next.push_back(k);
            }
            else
            {
                k = next[k];
            }
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int i=0;//源串
        int j=0;//子串
        int len1=haystack.size();
        int len2=needle.size();
        vector<int> next;
        next=getNext(needle);
        
        while((i<len1)&&(j<len2))
        {
            if((j==-1)||(haystack[i]==needle[j]))
            {
                i++;
                j++;
            }
            else
            {
                j=next[j];//获取下一次匹配的位置
            }
        }
        if(j==len2)
            return i-j;
        return -1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
