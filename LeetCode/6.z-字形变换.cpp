/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-10 16:13:38
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-10 16:48:02
 * @FilePath: \C++_Code\LeetCode\6.z-字形变换.cpp
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (48.27%)
 * Likes:    778
 * Dislikes: 0
 * Total Accepted:    157.2K
 * Total Submissions: 324.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 *
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 *
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 *
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 *
 * 请你实现这个将字符串进行指定行数变换的函数：
 *
 * string convert(string s, int numRows);
 *
 * 示例 1:
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 *
 *
 * 示例 2:
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 *
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
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
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string res;
        int str_len = s.size();

        for (int row_begin = 1; row_begin <= numRows; row_begin++)
        {
            int gap = numRows == row_begin ? 2 * (numRows - 1) : 2 * (numRows - row_begin);
            int idx = row_begin;
            while (idx <= str_len)
            {
                res += s[idx - 1];
                idx += gap;
                if (gap != 2 * (numRows - 1))
                    gap = 2 * (numRows - 1) - gap;
            }
        }
        return res;
    }
};
// @lc code=end
