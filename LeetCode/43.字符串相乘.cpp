/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (43.79%)
 * Likes:    464
 * Dislikes: 0
 * Total Accepted:    101.2K
 * Total Submissions: 227.4K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 *
 * 示例 1:
 *
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 *
 * 示例 2:
 *
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 *
 * 说明：
 *
 *
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
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
    string multiply(string num1, string num2)
    {
        // 有一个为0则返回0
        if (num1 == "0" || num2 == "0")
            return "0";

        string res = "0";
        int m = num1.size();
        int n = num2.size();

        for (int i = n - 1; i >= 0; i--)
        {
            int add = 0; // 定义进位
            string curr;
            // 把多出来的位数先加上
            for (int j = n - 1; j > i; j--)
            {
                curr.push_back(0);
            }
            int y = num2[i] - '0'; // 乘数
            for (int j = m - 1; j >= 0; j--)
            {
                int x = num1[j] - '0';
                auto result = x * y + add;
                curr.push_back(result % 10);
                add = result / 10;
            }
            while (add != 0)
            {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto &c : curr)
            {
                c += '0';
            }
            res = addString(curr, res);
        }
        return res;
    }

    // 使用字符串将两个字符串相加
    string addString(string &num1, string &num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c : ans)
        {
            c += '0';
        }
        return ans;
    }
};
// @lc code=end
