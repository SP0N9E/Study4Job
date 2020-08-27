/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-27 14:52:22
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-27 15:25:19
 * @FilePath: \C++_Code\LeetCode\47.全排列-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (59.58%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    83.2K
 * Total Submissions: 139.3K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 *
 * 示例:
 *
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> nums, int begin, int end)
    {
        if (begin == end - 1)
        {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < end; i++)
        {
            // 对于重复数字只需要考虑其中一个即可
            if (i != begin && nums[begin] == nums[i])
                continue;
            swap(nums[i], nums[begin]);
            backtrack(res, nums, begin + 1, end);
        }
    }

};
// @lc code=end
