/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.24%)
 * Likes:    368
 * Dislikes: 0
 * Total Accepted:    65.8K
 * Total Submissions: 159.5K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 *
 *
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 *
 *
 * 示例:
 *
 * 现有矩阵 matrix 如下：
 *
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 *
 *
 * 给定 target = 5，返回 true。
 *
 * 给定 target = 20，返回 false。
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
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;

        int rows = matrix.size();
        if (rows == 0)
            return found;
        int cols = matrix[0].size();

        if (rows>0 && cols > 0)
        {
            int row = 0;
            int col = cols-1;
            while (row<rows && col>=0)
            {
                if (matrix[row][col] == target)
                {
                    found = true;
                    return found;
                }
                else if (matrix[row][col] > target)
                {
                    --col;
                }
                else
                {
                    ++row;
                }


            }
        }
        return found;
    }
};
// @lc code=end

