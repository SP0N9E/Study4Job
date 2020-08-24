/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-23 10:53:36
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-23 12:06:18
 * @FilePath: \C++_Code\LeetCode\41.缺失的第一个正数.cpp
 */
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.19%)
 * Likes:    738
 * Dislikes: 0
 * Total Accepted:    84.4K
 * Total Submissions: 209.8K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [1,2,0]
 * 输出: 3
 *
 *
 * 示例 2:
 *
 * 输入: [3,4,-1,1]
 * 输出: 2
 *
 *
 * 示例 3:
 *
 * 输入: [7,8,9,11,12]
 * 输出: 1
 *
 *
 *
 *
 * 提示：
 *
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <assert.h>
#include <string>
#include <memory>
using namespace std;

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
            {
                Swap(nums, i, nums[i]-1);
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return size + 1;
    }

    void Swap(vector<int> &nums, int idx1, int idx2)
    {
        auto temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
};
// @lc code=end
