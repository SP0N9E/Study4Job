/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-15 18:07:14
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-15 22:39:14
 * @FilePath: \Study4Job\LeetCode\20.有效的括号.cpp
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (42.64%)
 * Likes:    1792
 * Dislikes: 0
 * Total Accepted:    379.8K
 * Total Submissions: 887.7K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 * 注意空字符串可被认为是有效字符串。
 *
 * 示例 1:
 *
 * 输入: "()"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "()[]{}"
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: "(]"
 * 输出: false
 *
 *
 * 示例 4:
 *
 * 输入: "([)]"
 * 输出: false
 *
 *
 * 示例 5:
 *
 * 输入: "{[]}"
 * 输出: true
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sta;
        bool res = false;
        for (int i = 0; i<s.size(); i++)
        {
            auto c = s[i];
            switch (c)
            {
            case '{':
            case '[':
            case '(': sta.push(c); break;
            case ')':
                if (sta.empty() || sta.top()!='(') return false;
                else sta.pop();
                break;
            case ']':
                if (sta.empty() || sta.top()!='[') return false;
                else sta.pop();
                break;
            case '}':
                if (sta.empty() || sta.top()!='{') return false;
                else sta.pop();
                break;

            default: ;
            }

        }
        return sta.empty();
    }
};
// @lc code=end
