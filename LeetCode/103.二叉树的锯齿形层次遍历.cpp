/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.54%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 104.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回锯齿形层次遍历如下：
 *
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    // 双stack
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        int level_idx = 1;
        stack<TreeNode *> stack1; // 奇数层
        stack<TreeNode *> stack2; // 偶数层
        stack1.push(root);

        while (!stack1.empty() || !stack2.empty())
        {
            vector<int> levelres;
            if (level_idx & 1) // 奇数
            {
                while (!stack1.empty())
                {
                    auto node = stack1.top();
                    stack1.pop();
                    levelres.push_back(node->val);
                    if (node->left)
                        stack2.push(node->left);
                    if (node->right)
                        stack2.push(node->right);
                }
            }
            else
            {
                while (!stack2.empty())
                {
                    auto node = stack2.top();
                    stack2.pop();
                    levelres.push_back(node->val);
                    if (node->right)
                        stack1.push(node->right);
                    if (node->left)
                        stack1.push(node->left);


                }
            }
            res.push_back(levelres);
            level_idx++;

        }
        return res;
    }

    // 普通层序遍历之后再反转
    vector<vector<int>> zigzagLevelOrder_1(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root != nullptr)
            q.push(root);
        int level_idx = 1;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> levelres;
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                levelres.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            if (level_idx % 2 == 1)
                res.push_back(levelres);
            else
            {
                res.push_back(vector<int>(levelres.rbegin(), levelres.rend()));
            }
            level_idx++;
        }
        return res;
    }
};
// @lc code=end
