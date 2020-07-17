/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-16 16:35:05
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-16 17:06:08
 * @FilePath: \C++_Code\LeetCode\50.pow-x-n.cpp
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (36.07%)
 * Likes:    443
 * Dislikes: 0
 * Total Accepted:    108.1K
 * Total Submissions: 299.5K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 *
 * 示例 1:
 *
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 *
 *
 * 示例 2:
 *
 * 输入: 2.10000, 3
 * 输出: 9.26100
 *
 *
 * 示例 3:
 *
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 * 说明:
 *
 *
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (n == 0)
            return 1;
        if (x - 0.0 == 0)
            return 1;
        if (x - 1.0 == 0)
            return 1;
        unsigned int exponent = (unsigned int)(N);
        if (N < 0)
            exponent = (unsigned int)(-N);
        //double result = PowUnsigned(x, exponent);
        double result = PowUnsignedAccelerate(x, exponent);

        if (n < 0)
        {
            result = 1.0 / result;
        }
        return result;
    }

    double PowUnsigned(double x, unsigned int exponent)
    {
        double res = 1;
        for (int i = 0; i<exponent;i++)
        {
            res *= x;
        }
        return res;
    }

    // 递归调用
    double PowUnsignedAccelerate(double x, unsigned int exponent)
    {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return x;
        auto result = PowUnsignedAccelerate(x, exponent >> 1);
        result *= result;
        if (exponent % 2 == 1)
        {
            result *= x;
        }
        return result;
    }
};
// @lc code=end

