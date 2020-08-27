/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (79.16%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 38.5K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 *
 *
 * 上图为 8 皇后问题的一种解法。
 *
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 *
 * 示例:
 *
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 *
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或
 * N-1 步，可进可退。（引用自 百度百科 - 皇后 ）
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
    int res = 0;
    int totalNQueens(int n)
    {
        vector<string> checkboard(n, string(n, '.'));
        backtrack(checkboard, 0);
        return res;
    }

    void backtrack(vector<string> &checkboard, int row)
    {
        if (row == checkboard.size())
        {
            res++;
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
