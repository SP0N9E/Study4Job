/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-21 17:05:20
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-21 17:13:13
 * @FilePath: \C++_Code\LeetCode\35.搜索插入位置.cpp
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (46.64%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    232.7K
 * Total Submissions: 498.9K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 *
 * 你可以假设数组中无重复元素。
 *
 * 示例 1:
 *
 * 输入: [1,3,5,6], 5
 * 输出: 2
 *
 *
 * 示例 2:
 *
 * 输入: [1,3,5,6], 2
 * 输出: 1
 *
 *
 * 示例 3:
 *
 * 输入: [1,3,5,6], 7
 * 输出: 4
 *
 *
 * 示例 4:
 *
 * 输入: [1,3,5,6], 0
 * 输出: 0
 *
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
    int searchInsert(vector<int> &nums, int target)
    {
        int ans = nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] >= target)
            {
                right = mid - 1;
                ans = mid;
            }

        }
        return ans;


    }
};
// @lc code=end
