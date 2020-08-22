/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (62.46%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    77.1K
 * Total Submissions: 123.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用一次。
 *
 * 说明：
 *
 *
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 *
 *
 * 示例 1:
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * 示例 2:
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
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
    vector<int> map;
    void backtrack(vector<int> &candidates, int next, vector<int> &record, int target, vector<vector<int>> &res)
    {
        // 相加为target 满足要求
        if (target == 0 && find(res.begin(), res.end(), record) == res.end())
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
        backtrack(candidates, next+1, record, target - candidates[next], res); // 无限制选取
        record.pop_back();                                                   // 回溯

        backtrack(candidates, next + 1, record, target, res);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        map = vector<int>(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> record;
        backtrack(candidates, 0, record, target, res);
        return res;
    }
};
// @lc code=end
