/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-24 09:57:14
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-24 10:58:20
 * @FilePath: \C++_Code\LeetCode\400.第n个数字.cpp
 */
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (37.53%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 26K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 *
 * 注意:
 * n 是正数且在32位整数范围内 ( n < 2^31)。
 *
 * 示例 1:
 *
 * 输入:
 * 3
 *
 * 输出:
 * 3
 *
 *
 * 示例 2:
 *
 * 输入:
 * 11
 *
 * 输出:
 * 0
 *
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
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
    int findNthDigit(int n)
    {
        // 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits++;
        }

        // 计算真实代表的数字是多少
        int idx = n % digits; // 注意由于上面的计算，n现在表示digits位数的第n个数字
        if (idx == 0)
            idx = digits;
        long number = 1;
        for (int i = 1; i < digits; i++)
            number *= 10;
        number += (idx == digits) ? n / digits - 1 : n / digits;

        // 从真实的数字中找到我们想要的那个数字
        for (int i = idx; i < digits; i++)
            number /= 10;
        return number % 10;
    }
};

// @lc code=end
