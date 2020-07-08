/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.87%)
 * Likes:    557
 * Dislikes: 0
 * Total Accepted:    186.2K
 * Total Submissions: 258.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> S;
        auto p = root;
        vector<int> res;
        while (S.size()||p)
        {
            while(p)
            {
                S.push(p);
                p = p->left;
            }
            // 弹出来
            p = S.top(); S.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }

    void inorderHelper(TreeNode *root, vector<int> &res)
    {
        if (root != nullptr)
        {
            inorderHelper(root->left, res);
            res.push_back(root->val);
            inorderHelper(root->right, res);
        }
        else
        {
            return;
        }
    }

    vector<int> res;
    vector<int> inorderTraversal_1(TreeNode *root)
    {
        vector<int> res_1;
        inorderHelper(root, res_1);
        // if (root)
        // {
        //     inorderTraversal(root->left);
        //     res.push_back(root->val);
        //     inorderTraversal(root->right);
        // }
        return res_1;
    }
};
// @lc code=end
