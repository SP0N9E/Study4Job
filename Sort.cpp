/*
 * @Author: SP0N9E
 * @Description: 排序算法自己实现。
 * @Date: 2020-07-15 16:35:34
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-18 20:23:18
 * @FilePath: \C++_Code\Sort.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &num, int low, int high)
{
    int pivot = num[low];
    while (low < high)
    {
        while (low < high && num[high] > pivot)
        {
            high--;
        }
        num[low] = num[high];
        while (low < high && num[low] < pivot)
        {
            low++;
        }
        num[high] = num[low];
    }
    num[low] = pivot;
    return low;
}

void QSortHelper(vector<int> &num, int low, int high)
{
    if (low < high)
    {
        int pivot_idx = partition(num, low, high);
        QSortHelper(num, low, pivot_idx - 1);
        QSortHelper(num, pivot_idx + 1, high);
    }
}

void QSort(vector<int> &num)
{
    QSortHelper(num, 0, num.size() - 1);
}

void Merge(vector<int> &num, int L1, int R1, int L2, int R2)
{
    //int tmp[R2 - L1 + 1];
    vector<int> tmp(R2 - L1 + 1);
    int i = L1;
    int j = L2;
    int k = 0;
    while (i <= R1 && j <= R2)
    {
        if (num[i] <= num[j])
            tmp[k++] = num[i++];
        else
            tmp[k++] = num[j++];
    }
    while (i <= R1)
    {
        tmp[k++] = num[i++];
    }
    while (j <= R2)
    {
        tmp[k++] = num[j++];
    }
    for (int i = 0; i < k; i++)
    {
        num[L1 + i] = tmp[i];
    }
}

void MergeSortHelper(vector<int> &num, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSortHelper(num, left, mid);
    MergeSortHelper(num, mid + 1, right);
    Merge(num, left, mid, mid + 1, right);
}

void MergeSort(vector<int> &num)
{
    MergeSortHelper(num, 0, num.size() - 1);
}

int main()
{

    vector<int> test = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
    MergeSort(test);
    for (auto tmp : test)
    {
        cout << tmp << " ";
    }
}