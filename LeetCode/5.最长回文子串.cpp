/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-10 14:49:43
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-10 15:29:28
 * @FilePath: \C++_Code\LeetCode\5.最长回文子串.cpp
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.03%)
 * Likes:    2541
 * Dislikes: 0
 * Total Accepted:    340.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
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
    string longestPalindrome_1(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string res;
        for (int len = 0; len < n; ++len) // 字串的长度 考虑下标因此从零开始
        {
            for (int i = 0; i + len < n; ++i)
            {
                int j = i + len;
                if (len == 0) // 字串长度为1
                    dp[i][j] = 1;
                else if (len == 1) // 字串长度为2 需要判断两个字符是否相等
                    dp[i][j] = (s[i] == s[j]);
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && len + 1 > res.size())
                {
                    res = s.substr(i, len + 1);
                }
            }
        }
        return res;
    }

    pair<int, int> expand(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    // 找到中心向外扩展的做法
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = expand(s, i, i);
            auto [left2, right2] = expand(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
// @lc code=end
