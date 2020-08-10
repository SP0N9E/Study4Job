/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-10 17:13:08
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-10 17:40:34
 * @FilePath: \C++_Code\LeetCode\9.回文数.cpp
 */
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.38%)
 * Likes:    1174
 * Dislikes: 0
 * Total Accepted:    416.1K
 * Total Submissions: 712.1K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 *
 * 输入: 121
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 *
 *
 * 示例 3:
 *
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 *
 *
 * 进阶:
 *
 * 你能不将整数转为字符串来解决这个问题吗？
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
class Solution {
public:
    bool isPalindrome_1(int x) {
        if (x < 0) // 负数不是回文数
            return false;
        if (x%10 == 0 && x!=0) // 个位是0的数不可能是回文
            return false;
        auto s = to_string(x);
        stack<char> st;
        for (int i = 0; i<s.size(); i++)
        {
            st.push(s[i]);
        }
        string s_res;
        while (!st.empty())
        {
            s_res += st.top();
            st.pop();
        }
        if (s_res == s)
            return true;
        else
        {
            return false;
        }

    }

    bool isPalindrome(int x) {
        if (x < 0) // 负数不是回文数
            return false;
        if (x%10 == 0 && x!=0) // 个位是0的数不可能是回文
            return false;
        int revertedNumber = 0;
        // 翻转一半
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;

    }
};
// @lc code=end

