/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-21 14:55:12
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-21 15:19:17
 * @FilePath: \C++_Code\LeetCode\31.下一个排列.cpp
 */
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.32%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    82.8K
 * Total Submissions: 240.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 *
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 *
 * 必须原地修改，只允许使用额外常数空间。
 *
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        // 找到第一个不是降序的数字
        while (i >= 0 && nums[i + 1] <= nums[i])
        {
            i--;
        }
        if (i >= 0)
        {
            // 找到第一个比nums[i]大的数字
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            MySwap(nums, i, j);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

    void MySwap(vector<int> &nums, int idx1, int idx2)
    {
        auto temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
};
// @lc code=end
