//
//  main.cpp
//  BCZF_2_1
//
//  Created by 王子昱 on 2019/9/23.
//  Copyright © 2019 王子昱. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector<int> &arr, int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(vector<int> &arr, int len) {
    // 初始化，i從最後一個父節點開始調整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    
    //    cout << "mid:" << endl;
    //    for (int item:arr) {cout << item << " ";}
    //    cout << endl;
    
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);

    }
}

void quickSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int key = arr[left];
        int i = left, j = right;
        while (i < j)
        {
            while (arr[j] > key && j > i)    //arr[j] > key可以换为arr[j] >= key，但j > i不可以换为j >= i，边界问题
                j--;
            if (i < j)
            {
                arr[i] = arr[j];
                i += 1;
            }
            while (arr[i] < key && i < j)    //同理
                i++;
            if (i < j)
            {
                arr[j] = arr[i];
                j -= 1;
            }
        }
        arr[i] = key;      //此时不用纠结是arr[i] = key还是arr[j] = key，因为i = j
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
        return;
    }
}

void min_heapify(vector<int> &arr, int start, int end)
{
//    end:index
    int parent = start;
    int son = parent * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] > arr[son+1]) {
            son += 1;
        }
        if (arr[parent] < arr[son]) {
            return;
        }
        swap(arr[parent], arr[son]);
        parent = son;
        son = parent * 2 + 1;
    }
    return;
}
void heap_sort_min_heap(vector<int> &arr, int len)
{
    for (int i = len / 2 - 1; i >=0 ; i --) {
        min_heapify(arr, i, len - 1);
    }
    for (int i = len - 1; i > 0; i -- ) {
        swap(arr[0], arr[i]);
        min_heapify(arr, 0, i - 1);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //    vector<int> arr = {1,3,4,5,7,9,2,6,8,11};
    vector<int> arr = {0,1,2,3,4,5,6};
    
    heap_sort(arr, arr.size());
    for (int item:arr) {
        cout << item << endl;
    }
    
    vector<int> arr2 = {11,1,2,3,4,5,6};
    
    quickSort(arr2, 0, arr2.size() - 1);
    
    for (int items : arr2) {
        cout << items << endl;
    }
    
    cout << "min_heap" <<endl;
    vector<int> arr3 = {11,1,2,3,4,5,6};
    heap_sort_min_heap(arr3, arr3.size());

    for (int items : arr3) {
        cout << items << endl;
    }
    

    
    return 0;
}
