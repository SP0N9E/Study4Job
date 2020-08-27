/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-27 17:28:36
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-27 17:52:48
 * @FilePath: \C++_Code\LeetCode\51.n皇后.cpp
 */
/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-27 17:28:36
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-27 17:51:19
 * @FilePath: \C++_Code\LeetCode\51.n皇后.cpp
 */
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (70.64%)
 * Likes:    516
 * Dislikes: 0
 * Total Accepted:    58.2K
 * Total Submissions: 82.2K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 *
 *
 * 上图为 8 皇后问题的一种解法。
 *
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 *
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 * 示例:
 *
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 *
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自
 * 百度百科 - 皇后 ）
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
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> checkboard(n, string(n, '.'));
        backtrack(checkboard, 0);
        return res;
    }

    void backtrack(vector<string> &checkboard, int row)
    {
        if (row == checkboard.size())
        {
            res.push_back(checkboard);
            return;
        }
        auto n = checkboard[row].size();
        for (int col = 0; col < n; col++)
        {
            // 去除不合法的选择
            if (isvalid(checkboard, row, col) == false)
            {
                continue;
            }
            checkboard[row][col] = 'Q';
            backtrack(checkboard, row + 1);
            checkboard[row][col] = '.';
        }
    }

    bool isvalid(const vector<string> &checkboard, int row, int col)
    {
        int n = checkboard.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++)
        {
            if (checkboard[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++)
        {
            if (checkboard[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--)
        {
            if (checkboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
// @lc code=end
