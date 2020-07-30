/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-27 14:22:02
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-27 14:57:31
 * @FilePath: \C++_Code\LeetCode\3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.05%)
 * Likes:    4044
 * Dislikes: 0
 * Total Accepted:    585.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 1)
            return 1;
        map<char, int> myMap;
        int curLength = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int letterIdx;
            if (myMap.find(s[i]) == myMap.end()) // 没找到
            {
                curLength++;
            }
            else
            {
                letterIdx = myMap[s[i]];
                if (i - letterIdx > curLength)
                    curLength++;
                else
                {
                    if (curLength > maxLength)
                        maxLength = curLength;
                    curLength = i - letterIdx;
                }
            }
            myMap[s[i]] = i;
        }
        if (curLength > maxLength)
            maxLength = curLength;
        return maxLength;
    }
};
// @lc code=end
