/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-23 19:49:14
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-24 15:28:16
 * @FilePath: \C++_Code\LeetCode\42.接雨水.cpp
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.17%)
 * Likes:    1576
 * Dislikes: 0
 * Total Accepted:    137.6K
 * Total Submissions: 263.1K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 *
 * 示例:
 *
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
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
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
            return 0;
        int size = height.size();
        int res = 0;
        vector<int> left_max(size);
        vector<int> right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[size - 1] = height[size - 1];
        for (int j = size - 2; j >= 0; j--)
        {
            right_max[j] = max(right_max[j + 1], height[j]);
        }
        for (int i = 1; i < size - 1; i++)
        {
            res += min(right_max[i], left_max[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end
