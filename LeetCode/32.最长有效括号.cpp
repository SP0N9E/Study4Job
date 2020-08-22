/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-21 15:21:04
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-21 16:05:16
 * @FilePath: \C++_Code\LeetCode\32.最长有效括号.cpp
 */
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (33.47%)
 * Likes:    914
 * Dislikes: 0
 * Total Accepted:    95.3K
 * Total Submissions: 283.7K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 示例 1:
 *
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 *
 * 示例 2:
 *
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
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
    // 使用动态规划的方法  但是其实我没有很理解(
    int longestValidParentheses_1(string s)
    {
        int res = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
    // 使用栈的方法
    int longestValidParentheses(string s)
    {
        stack<int > sta;
        sta.push(-1);
        int res =0;
        for (int i = 0; i<s.size();i++)
        {
            if (s[i] =='(')
            {
                sta.push(i);
            }
            else
            {
                sta.pop();
                if (sta.empty())
                {
                    sta.push(i);
                }
                else
                {
                    res = max(res, i-sta.top());
                }

            }

        }
        return res;
    }
};
// @lc code=end