/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-01 19:40:26
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-01 22:03:50
 * @FilePath: \C++_Code\LeetCode\300.最长上升子序列.cpp
 */
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.76%)
 * Likes:    859
 * Dislikes: 0
 * Total Accepted:    123.2K
 * Total Submissions: 274.1K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 *
 * 示例:
 *
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 *
 * 说明:
 *
 *
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 *
 *
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
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
    // 二分搜索的方法
    int lengthOfLIS(vector<int> &nums)
    {

    }
    // 动态规划的方法
    int lengthOfLIS_1(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int res = 0;
        for (int i =0 ; i<dp.size(); i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end
