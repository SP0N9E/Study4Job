/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-04 15:12:49
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-04 15:43:55
 * @FilePath: \C++_Code\LeetCode\518.零钱兑换-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode-cn.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (53.54%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 40K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
 *
 *
 *
 *
 *
 *
 * 示例 1:
 *
 * 输入: amount = 5, coins = [1, 2, 5]
 * 输出: 4
 * 解释: 有四种方式可以凑成总金额:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * 示例 2:
 *
 * 输入: amount = 3, coins = [2]
 * 输出: 0
 * 解释: 只用面额2的硬币不能凑成总金额3。
 *
 *
 * 示例 3:
 *
 * 输入: amount = 10, coins = [10]
 * 输出: 1
 *
 *
 *
 *
 * 注意:
 *
 * 你可以假设：
 *
 *
 * 0 <= amount (总金额) <= 5000
 * 1 <= coin (硬币面额) <= 5000
 * 硬币种类不超过 500 种
 * 结果符合 32 位符号整数
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
    // 未优化空间
    int change_1(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j - coins[i - 1] >= 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][amount];
    }
    // 优化了空间
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int i= 0; i<n;i++)
        {
            for (int j = 1; j<=amount; j++)
            {
                if (j - coins[i] >= 0)
                    dp[j] = dp[j] + dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};
// @lc code=end
