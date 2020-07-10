/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (31.57%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    139K
 * Total Submissions: 438.7K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 *
 * 假设一个二叉搜索树具有如下特征：
 *
 *
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 * 示例 1:
 *
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // 递归
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode *root, long min, long max)
    {
        if (root == nullptr)
            return true;
        if (root->val < min || root->val > max)
            return false;
        bool left = dfs(root->left, min, root->val - 1l);
        bool right = dfs(root->right, root->val + 1l, max);
        return left && right;
    }

    // 中序遍历
    bool isValidBST_1(TreeNode *root)
    {
        stack<TreeNode *> s;
        auto p = root;
        long long MIN = (long long)INT_MIN - 1;
        while (s.size() || p != nullptr)
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (p->val <= MIN)
                return false;
            MIN = p->val;
            p = p->right;
        }
        return true;
    }
};
// @lc code=end
