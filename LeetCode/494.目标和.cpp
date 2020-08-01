/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-01 17:44:02
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-01 18:07:41
 * @FilePath: \C++_Code\LeetCode\494.目标和.cpp
 */
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.39%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    37.4K
 * Total Submissions: 84.3K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 *
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 *
 *
 *
 * 示例：
 *
 * 输入：nums: [1, 1, 1, 1, 1], S: 3
 * 输出：5
 * 解释：
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * 一共有5种方法让最终目标和为3。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 数组非空，且长度不会超过 20 。
 * 初始的数组的和不会超过 1000 。
 * 保证返回的最终结果能被 32 位整数存下。
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
    // 回溯法
    int result = 0;
    int findTargetSumWays_1(vector<int> &nums, int S)
    {
        if (nums.size() == 0)
            return 0;
        backtrack(nums, 0, S);
        return result;
    }

    void backtrack(vector<int> &nums, int i, int rest)
    {
        if (i == nums.size())
        {
            if (rest == 0)
                result++;
            return;
        }

        rest += nums[i];
        backtrack(nums, i + 1, rest);
        rest -= nums[i];

        rest -= nums[i];
        backtrack(nums, i + 1, rest);
        rest += nums[i];
    }

    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum < S || (sum + S) % 2 == 1)
        {
            return 0;
        }
        return subsets(nums, (sum + S) / 2);
    }

    int subsets(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
// @lc code=end
