/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 *
 * https://leetcode-cn.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (63.92%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    106.3K
 * Total Submissions: 165.8K
 * Testcase Example:  '3'
 *
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 *
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 *
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 *
 *
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 *
 *
 * 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
 *
 * 示例 1:
 *
 * 输入: 3
 * 输出: "III"
 *
 * 示例 2:
 *
 * 输入: 4
 * 输出: "IV"
 *
 * 示例 3:
 *
 * 输入: 9
 * 输出: "IX"
 *
 * 示例 4:
 *
 * 输入: 58
 * 输出: "LVIII"
 * 解释: L = 50, V = 5, III = 3.
 *
 *
 * 示例 5:
 *
 * 输入: 1994
 * 输出: "MCMXCIV"
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
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
    // 找规律实现
    string intToRoman_1(int num)
    {
        string res = intToRomanOneBit(num / 1000, 'M', 0, 0)               // 处理千位
                     + intToRomanOneBit((num % 1000) / 100, 'C', 'D', 'M') // 处理百位
                     + intToRomanOneBit((num % 100) / 10, 'X', 'L', 'C')   // 处理十位
                     + intToRomanOneBit(num % 10, 'I', 'V', 'X');          // 处理个位
        return res;
    }

    string intToRomanOneBit(int num, char one, char five, char ten)
    {
        if (num <= 3)
        {
            return string(num, one);
        }
        else if (num == 4)
        {
            return string("") + one + five;
        }
        else if (num <= 8)
        {
            return string("") + five + string(num - 5, one);
        }
        return string("") + one + ten;
    }

    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    // 贪心算法
    string intToRoman(int num)
    {
        string res;
        for (int i = 0; i<values.size(); i++)
        {
            while (values[i] <= num)
            {
                num-=values[i];
                res += symbols[i];
            }
        }
        return res;
    }
};
// @lc code=end
