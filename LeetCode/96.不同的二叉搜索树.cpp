/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (65.98%)
 * Likes:    605
 * Dislikes: 0
 * Total Accepted:    52.2K
 * Total Submissions: 79K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 *
 * 示例:
 *
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 *
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1);
        G[0] = 1; G[1] = 1;
        for (int i = 2; i<=n;i++)
        {
            for (int j = 1; j<=i;j++)
            {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};
// @lc code=end

