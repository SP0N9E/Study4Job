/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-17 14:21:32
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-17 14:53:26
 * @FilePath: \C++_Code\LeetCode\54.螺旋矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (40.72%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    68.9K
 * Total Submissions: 169.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *
 * 示例 1:
 *
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2:
 *
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int rows = matrix.size();
        if (rows == 0)
            return res;

        int p_row = 0, p_col = 0;
        int direction = 1;

        int cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));


        while (PointAccess(p_row, p_col, rows, cols, visited))
        {
            res.push_back(matrix[p_row][p_col]);
            visited[p_row][p_col] = true;

            switch (direction)
            {
            case 1:
                if (PointAccess(p_row, p_col + 1, rows, cols, visited))
                    p_col += 1;
                else
                {
                    direction++;
                    p_row += 1;
                }
                break;
            case 2:
                if (PointAccess(p_row + 1, p_col, rows, cols, visited))
                    p_row += 1;
                else
                {
                    direction++;
                    p_col -= 1;
                }
                break;
            case 3:
                if (PointAccess(p_row, p_col - 1, rows, cols, visited))
                    p_col -= 1;
                else
                {
                    direction++;
                    p_row -= 1;
                }
                break;
            case 4:
                if (PointAccess(p_row - 1, p_col, rows, cols, visited))
                    p_row -= 1;
                else
                {
                    direction = 1;
                    p_col += 1;
                }
                break;

            default:
                break;
            }
        }
        return res;
    }

    bool PointAccess(int p_row, int p_col, int rows, int cols, const vector<vector<bool>> &visited)
    {
        if (p_row >= 0 && p_row < rows && p_col >= 0 && p_col < cols && visited[p_row][p_col] == false)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
