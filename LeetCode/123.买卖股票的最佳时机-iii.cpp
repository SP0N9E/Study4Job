/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (43.42%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 97.2K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 *
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 示例 1:
 *
 * 输入: [3,3,5,0,0,3,1,4]
 * 输出: 6
 * 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 *
 * 示例 2:
 *
 * 输入: [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。  
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 *
 *
 * 示例 3:
 *
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    // int maxProfit(vector<int> &prices)
    // {
    //     if (prices.size() <= 1)
    //         return 0;
    //     int size = prices.size();
    //     vector<vector<vector<int>>> dp(size, vector<vector<int>>(2, vector<int>(3)));

    //     dp[0][0][0] = 0;

    //     dp[0][1][0] = -prices[0];

    //     dp[0][0][1] = -INT_MAX;
    //     dp[0][0][2] = -INT_MAX;

    //     dp[0][1][1] = -INT_MAX;
    //     dp[0][1][2] = -INT_MAX;

    //     for (int i = 1; i < size; i++)
    //     {

    //         dp[i][0][0] = 0;
    //         dp[i][0][1] = max(dp[i - 1][1][0] + prices[i], dp[i - 1][0][1]);
    //         dp[i][0][2] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][2]);
    //         dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0]);
    //         dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1]);
    //         dp[i][1][2] = -INT_MAX;
    //     }
    //     return max(dp[size - 1][0][1], dp[size - 1][0][2]);
    // }
    // 看了题解之后的
    int maxProfit_1(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int size = prices.size();
        int max_k = 2;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(3, vector<int>(2)));
        for (int i = 0; i < size; i++)
        {
            for (int k = max_k; k >= 1; k--)
            {
                if (i - 1 == -1)
                {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[0];
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        return dp[size - 1][max_k][0];
    }
};
// @lc code=end
