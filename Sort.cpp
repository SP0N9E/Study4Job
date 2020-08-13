/*
 * @Author: SP0N9E
 * @Description: 排序算法自己实现。
 * @Date: 2020-07-15 16:35:34
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-12 13:21:51
 * @FilePath: \C++_Code\Sort.cpp
 */

#include <iostream>
#include <vector>
#include<stack>
using namespace std;

int partition(vector<int> &num, int low, int high)
{
    int pivot = num[low];
    while (low < high)
    {
        while (low < high && num[high] >= pivot)
        {
            high--;
        }
        num[low] = num[high];
        while (low < high && num[low] <= pivot)
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

// 非递归版本
void QSortHelper2(vector<int> &a, int left,int right)
{
    if (a.size() == 0|| left < 0 || right <= 0 || left>right)
        return;
    stack<int>temp;
    int i, j;
    //（注意保存顺序）先将初始状态的左右指针压栈
    temp.push(right);//先存右指针
    temp.push(left);//再存左指针
    while (!temp.empty())
    {
        i = temp.top();//先弹出左指针
        temp.pop();
        j = temp.top();//再弹出右指针
        temp.pop();
        if (i < j)
        {
            int k = partition(a, i, j);
            if (k > i)
            {
                temp.push(k - 1);//保存中间变量
                temp.push(i);  //保存中间变量
            }
            if (j > k)
            {
                temp.push(j);
                temp.push(k + 1);
            }
        }

    }

}

void QSort(vector<int> &num)
{
    //QSortHelper(num, 0, num.size() - 1);
    QSortHelper2(num, 0, num.size() - 1);
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

void maxHeapify(vector<int> &num, int i, int len)
{
    for (; (i << 1) + 1 <= len;)
    {
        int lson = (i << 1) + 1;
        int rson = (i << 1) + 2;
        int large;
        if (lson <= len && num[lson] > num[i])
        {
            large = lson;
        }
        else
        {
            large = i;
        }
        if (rson <= len && num[rson] > num[large])
        {
            large = rson;
        }
        if (large != i)
        {
            swap(num[i], num[large]);
            i = large;
        }
        else
            break;
    }
}


void minHeapify(vector<int> &num, int i, int len)
{
    for (; (i << 1) + 1 <= len;)
    {
        int lson = (i << 1) + 1;
        int rson = (i << 1) + 2;
        int small;
        if (lson <= len && num[lson] < num[i])
        {
            small = lson;
        }
        else
        {
            small = i;
        }
        if (rson <= len && num[rson] < num[small])
        {
            small = rson;
        }
        if (small != i)
        {
            swap(num[i], num[small]);
            i = small;
        }
        else
            break;
    }
}


void buildMaxHeap(vector<int> &num, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        maxHeapify(num, i, len);
    }
}

void buildMinHeap(vector<int> &num, int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        minHeapify(num, i, len);
    }
}

void HeapSort(vector<int> &num)
{
    int len = num.size() - 1;
    //buildMaxHeap(num, len);
    buildMinHeap(num, len);
    for (int i = len; i >= 1; --i)
    {
        swap(num[i], num[0]);
        len -= 1;
        //maxHeapify(num, 0, len);
        minHeapify(num, 0, len);
    }
}

int main()
{

    vector<int> test = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
    //vector<int> test = {5, 1, 1, 2, 0, 0};
    QSort(test);
    for (auto tmp : test)
    {
        cout << tmp << " ";
    }
}