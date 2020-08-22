/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-22 18:46:32
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-22 18:56:06
 * @FilePath: \C++_Code\LeetCode\39.组合总和.cpp
 */
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (69.46%)
 * Likes:    831
 * Dislikes: 0
 * Total Accepted:    125.4K
 * Total Submissions: 180.4K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明：
 *
 *
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1：
 *
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * 示例 2：
 *
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
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
    void backtrack(vector<int> &candidates, int next, vector<int> &record, int target, vector<vector<int>> &res)
    {
        // 相加为target 满足要求
        if (target == 0)
        {
            res.push_back(record);
            return;
        }
        // 到达末尾 或者 target为负数
        if (next == candidates.size() || target - candidates[next] < 0)
        {
            return;
        }
        record.push_back(candidates[next]);
        //target = target - candidates[next];
        backtrack(candidates, next, record, target - candidates[next], res); // 无限制选取
        record.pop_back();                                                   // 回溯

        backtrack(candidates, next + 1, record, target, res);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> record;
        backtrack(candidates, 0, record, target, res);
        return res;
    }
};
// @lc code=end
