/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-27 13:26:45
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-27 14:50:01
 * @FilePath: \C++_Code\LeetCode\46.全排列.cpp
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.63%)
 * Likes:    857
 * Dislikes: 0
 * Total Accepted:    178.3K
 * Total Submissions: 232.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 *
 * 示例:
 *
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> record;
        vector<vector<int>> res;
        backtrack(res, nums, record, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums, vector<int> &record, int pos)
    {
        if (pos == nums.size())
        {
            res.push_back(record);
            return;
        }
        for (int i = 0; i <= record.size(); i++)
        {
            record.insert(record.begin() + i, nums[pos]);
            backtrack(res, nums, record, pos + 1);
            record.erase(record.begin() + i);
        }
        return;
    }
};
// @lc code=end
