/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-15 22:39:53
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-15 23:02:30
 * @FilePath: \Study4Job\LeetCode\22.括号生成.cpp
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.00%)
 * Likes:    1235
 * Dislikes: 0
 * Total Accepted:    163.8K
 * Total Submissions: 215.5K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *
 *
 * 示例：
 *
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    // 回溯法遍历
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string current;
        backtrack(res, current, 0,0,n);
        return res;
    }

    void backtrack(vector<string>& res, string& current, int open, int end, int n)
    {
        if (current.size() == 2*n)
        {
            res.push_back(current);
            return;
        }
        if (open < n)
        {
            current+='(';
            backtrack(res, current, open+1, end,n);
            current.pop_back();
        }
        if (end < open )
        {
            current+=')';
            backtrack(res, current, open, end+1,n);
            current.pop_back();
        }
    }

    // 暴力法直接遍历所有可能 然后逐个检查合法性
    vector<string> generateParenthesis_1(int n)
    {
        vector<string> res;
        string current;
        generate_all(current, 2 * n, res);
        return res;
    }

    void generate_all(string &current, int number, vector<string> &res)
    {
        if (number == current.size())
        {
            if (ifValid(current))
            {
                res.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, number, res);
        current.pop_back();
        current += ')';
        generate_all(current, number, res);
        current.pop_back();
    }

    bool ifValid(const string &current)
    {
        int count = 0;
        for (auto c : current)
        {
            if (c == '(')
                count++;
            else
            {
                --count;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }
};
// @lc code=end
