/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 *
 * https://leetcode-cn.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (66.69%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    62.7K
 * Total Submissions: 94K
 * Testcase Example:  '2'
 *
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 *
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 *
 *
 * 给定 N，计算 F(N)。
 *
 *
 *
 * 示例 1：
 *
 * 输入：2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
 *
 *
 * 示例 2：
 *
 * 输入：3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
 *
 *
 * 示例 3：
 *
 * 输入：4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 ≤ N ≤ 30
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
using namespace std;

// @lc code=start
class Solution
{
public:
    // 迭代再优化
    int fib(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1 || N == 2)
            return 1;
        int curr = 1, prev = 1;
        for (int i = 3; i<=N;i++)
        {
            int sum = prev+curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }

    // 迭代解法
    int fib_3(int N)
    {
        if (N == 0)
            return 0;
        vector<int> dp(N + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[N];
    }

    // 带备忘录的DP
    int fib_2(int N)
    {
        if (N == 0)
            return 0;
        vector<int> record(N, 0);
        return fibHelper(record, N);
    }

    int fibHelper(vector<int> &record, int n)
    {
        if (n == 1 || n == 2)
            return 1;
        if (record[n - 1] != 0)
            return record[n - 1];
        return fibHelper(record, n - 1) + fibHelper(record, n - 2);
    }

    // 暴力穷举
    int fib_1(int N)
    {
        if (N == 0 || N == 1)
            return N;
        return fib(N - 1) + fib(N - 2);
    }
};
// @lc code=end
