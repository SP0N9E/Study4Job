/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-17 11:37:32
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-17 12:09:50
 * @FilePath: \C++_Code\LeetCode\226.翻转二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (75.75%)
 * Likes:    499
 * Dislikes: 0
 * Total Accepted:    96.2K
 * Total Submissions: 126.9K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 *
 * 示例：
 *
 * 输入：
 *
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 *
 * 输出：
 *
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 *
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 *
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
 *
 */

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    // 迭代版本
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            // 交换
            auto tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left!=nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        return root;

    }
    // 递归版本
    TreeNode *invertTree_1(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        if (root->left == nullptr && root ->right == nullptr)
            return root;
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left!=nullptr)
            root->left = invertTree(root->left);
        if (root->right!=nullptr)
            root->right = invertTree(root->right);
        return root;
    }
};
// @lc code=end
