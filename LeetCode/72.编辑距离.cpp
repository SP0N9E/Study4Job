/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-04 15:46:31
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-04 16:32:40
 * @FilePath: \C++_Code\LeetCode\72.编辑距离.cpp
 */
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (59.51%)
 * Likes:    1021
 * Dislikes: 0
 * Total Accepted:    73.4K
 * Total Submissions: 122.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
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
    int minDistance_1(string word1, string word2)
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> map(size1, vector<int>(size2, -1));
        return calculateDP(word1.size() - 1, word2.size() - 1, word1, word2, map);
    }

    int calculateDP(int i1, int i2, string word1, string word2, vector<vector<int>> &map)
    {
        if (i1 == -1)
            return i2 + 1;
        if (i2 == -1)
            return i1 + 1;
        if (map[i1][i2] != -1)
            return map[i1][i2];
        if (word1[i1] == word2[i2])
            map[i1][i2] = calculateDP(i1 - 1, i2 - 1, word1, word2, map);
        else
        {
            auto change = calculateDP(i1 - 1, i2 - 1, word1, word2, map) + 1;
            auto del = calculateDP(i1 - 1, i2, word1, word2, map) + 1;
            auto insert = calculateDP(i1, i2 - 1, word1, word2, map) + 1;
            map[i1][i2] = min(change, min(del, insert));
        }
        return map[i1][i2];
    }

    int minDistance(string word1, string word2)
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i <= size1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= size2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= size1; i++)
        {
            for (int j = 1; j <= size2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = MyMin(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[size1][size2];
    }

    int MyMin(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
};
// @lc code=end
