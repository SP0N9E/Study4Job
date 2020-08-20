/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-20 20:37:11
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-20 21:25:26
 * @FilePath: \C++_Code\LeetCode\29.两数相除.cpp
 */
/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (20.07%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    59.4K
 * Total Submissions: 295.8K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 *
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 *
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 *
 *
 *
 * 示例 1:
 *
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 *
 * 示例 2:
 *
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 *
 *
 *
 * 提示：
 *
 *
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
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
    // 简单概括为60/8 = (60-32)/8 + 4 = (60-32-16)/8 + 2 + 4 = 1 + 2 + 4 = 7
    int divide_1(int dividend, int divisor)
    {
        // 对特殊的除数返回特定的值
        if (divisor == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
                return -dividend;
            return INT_MAX;
        }
        // 确定符号
        long a = dividend;
        long b = divisor;
        int sign = 1;
        if ((a < 0 && b > 0) || (a > 0 && b < 0))
        {
            sign = -1;
        }
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        auto res = calcuDiv(a, b);
        if (sign == 1)
            return res > INT_MAX ? INT_MAX : res;
        return -res;
    }

    long calcuDiv(long a, long b)
    {
        // 被除数比除数小
        if (a < b)
            return 0;
        long count = 1;
        long tb = b;
        while (tb + tb <= a)
        {
            count = count + count;
            tb = tb + tb;
        }
        return count + calcuDiv(a - tb, b);
    }

    // Basic idea: a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))
    int divide(int dividend, int divisor)
    {
        // 处理特殊输入
        if (dividend == 0)
            return 0;
        if (divisor == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
                return -dividend;
            return INT_MAX;
        }
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            res = -res;
        }
        if (res > INT_MAX)
            res = INT_MAX;
        return res;
    }
};
// @lc code=end
