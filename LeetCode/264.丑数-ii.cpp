/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-27 15:01:18
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-27 15:23:23
 * @FilePath: \C++_Code\LeetCode\264.丑数-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (52.93%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    30.2K
 * Total Submissions: 56.7K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 *
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 *
 * 示例:
 *
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 *
 * 说明:  
 *
 *
 * 1 是丑数。
 * n 不超过1690。
 *
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> uglyArray(1690, 0);
        uglyArray[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int foundCount = 1;
        while (foundCount < n)
        {
            auto ugly = MyMin(uglyArray[p2] * 2, uglyArray[p3] * 3, uglyArray[p5] * 5);
            uglyArray[foundCount] = ugly;
            if (ugly == uglyArray[p2] * 2)
                p2++;
            if (ugly == uglyArray[p3] * 3)
                p3++;
            if (ugly == uglyArray[p5] * 5)
                p5++;
            foundCount++;
        }
        return uglyArray[n-1];
    }

    int MyMin(int n1, int n2, int n3)
    {
        return min(min(n1, n2), n3);
    }
};
// @lc code=end
