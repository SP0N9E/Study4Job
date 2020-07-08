/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (65.94%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    127.4K
 * Total Submissions: 193.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 *
 * 示例:
 *
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * 输出: [1,2,3]
 *
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
class Solution {
public:
    // 迭代版本
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> res;
        auto p = root;
        while (S.size() || p)
        {
            while(p)
            {
                res.push_back(p->val);
                S.push(p->right);
                p = p->left;
            }
            // 弹出
            p = S.top(); S.pop();
        }
        return res;

    }
    void preorderHelper(TreeNode* root, vector<int>& res)
    {
        if (root)
        {
            res.push_back(root->val);
            preorderHelper(root->left, res);
            preorderHelper(root->right, res);
        }
        else
        {
            return;
        }

    }
    // 递归版本
    vector<int> preorderTraversal_1(TreeNode* root) {
        vector<int > res;
        preorderHelper(root, res);
        return res;
    }


};
// @lc code=end

