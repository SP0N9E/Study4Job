/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-18 20:24:04
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-18 20:54:42
 * @FilePath: \C++_Code\LeetCode\912.排序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (59.14%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    72.1K
 * Total Submissions: 121.9K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        HeapSort(nums);
        return nums;
    }

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

    void buildMaxHeap(vector<int> &num, int len)
    {
        for (int i = len / 2; i >= 0; i--)
        {
            maxHeapify(num, i, len);
        }
    }
    void HeapSort(vector<int> &num)
    {
        int len = num.size() - 1;
        buildMaxHeap(num, len);
        for (int i = len; i >= 1; --i)
        {
            swap(num[i], num[0]);
            len -= 1;
            maxHeapify(num, 0, len);
        }
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
};
// @lc code=end
