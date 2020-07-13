/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (38.39%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    51K
 * Total Submissions: 132.8K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 *
 *
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 * 示例 1:
 *
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
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
    // 二分查找
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        bool found = false;

        int rows = matrix.size();
        if (rows == 0)
            return found;
        int cols = matrix[0].size();

        int left = 0;
        int right = rows*cols-1;
        int pivot_idx, pivot_element;
        while (left <= right)
        {
            pivot_idx = (left + right) / 2;
            pivot_element = matrix[pivot_idx / cols][pivot_idx%cols];
            if (pivot_element == target)
            {
                found = true;
                return found;
            }
            else
            {
                if (target < pivot_element)
                    right = pivot_idx - 1;
                else
                {
                    left = pivot_idx+1;
                }

            }

        }
        return found;

    }
    // 直接套用也可以
    bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
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

