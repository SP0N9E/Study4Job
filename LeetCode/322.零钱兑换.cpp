/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (40.14%)
 * Likes:    696
 * Dislikes: 0
 * Total Accepted:    101.8K
 * Total Submissions: 252.9K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 *
 *
 *
 * 示例 1:
 *
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3
 * 解释: 11 = 5 + 5 + 1
 *
 * 示例 2:
 *
 * 输入: coins = [2], amount = 3
 * 输出: -1
 *
 *
 *
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
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
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.rbegin(), coins.rend());
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            for (int coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        else
        {
            return dp[amount];
        }
    }
};
// @lc code=end
