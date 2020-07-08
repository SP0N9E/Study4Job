/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (71.78%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    92.7K
 * Total Submissions: 129K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> S;
        vector<int> res;
        auto p = root;
        while (p || S.size())
        {
            while (p)
            {
                res.push_back(p->val);
                S.push(p->left);
                p = p->right;
            }
            p = S.top();
            S.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> postorderTraversal_1(TreeNode *root)
    {
        vector<int> res;
        postorderHelper(root, res);
        return res;
    }

    void postorderHelper(TreeNode *root, vector<int> &res)
    {
        if (root)
        {
            postorderHelper(root->left, res);
            postorderHelper(root->right, res);
            res.push_back(root->val);
        }
        else
        {
            return;
        }
    }
};
// @lc code=end
