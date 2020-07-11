/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (49.90%)
 * Likes:    375
 * Dislikes: 0
 * Total Accepted:    113.6K
 * Total Submissions: 223.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 *
 *
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    // BFS 迭代
    bool hasPathSum(TreeNode *root, int sum)
    {
        if(root == nullptr)
            return false;
        queue<TreeNode*> qNode;
        queue<int> qSum;
        qNode.push(root);
        qSum.push(root->val);
        while(!qNode.empty())
        {
            auto node = qNode.front();
            auto tmp_sum = qSum.front();
            qNode.pop();
            qSum.pop();

            // 叶节点
            if (node->left == nullptr && node->right == nullptr)
            {
                if (tmp_sum == sum)
                    return true;
                continue;
            }
            if (node->left!=nullptr)
            {
                qNode.push(node->left);
                qSum.push(node->left->val + tmp_sum);
            }

            if (node->right != nullptr)
            {
                qNode.push(node->right);
                qSum.push(node->right->val + tmp_sum);
            }
        }
        return false;
    }
    // DFS递归迭代
    bool hasPathSum_1(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        if (!root->left && !root->right)
        {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end
