/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (42.07%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    69.6K
 * Total Submissions: 165.5K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 *
 *
 * 示例:
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 *
 *
 *
 * 提示：
 *
 *
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
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
using namespace std;

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word == "" || board.size() == 0)
            return false;

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int pathLength = 0;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (pathHelper(board, word, visited, rows, cols, row, col, pathLength))
                    return true;
            }
        }
        return false;
    }

    // 实际寻找的函数
    bool pathHelper(vector<vector<char>> &board, string word, vector<vector<bool>> &visited,
                    int rows, int cols, int row, int col, int &pathLength)
    {
        if (word[pathLength] == '\0')
            return true;

        bool hasPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == word[pathLength] && !visited[row][col])
        {
            ++pathLength;
            visited[row][col] = true;
            hasPath = pathHelper(board, word, visited, rows, cols, row - 1, col, pathLength) ||
                      pathHelper(board, word, visited, rows, cols, row + 1, col, pathLength) ||
                      pathHelper(board, word, visited, rows, cols, row, col - 1, pathLength) ||
                      pathHelper(board, word, visited, rows, cols, row, col + 1, pathLength);

            if (!hasPath)
            {
                visited[row][col] = false;
                --pathLength;
            }
        }
        return hasPath;
    }
};
// @lc code=end
