/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (52.32%)
 * Likes:    895
 * Dislikes: 0
 * Total Accepted:    172.5K
 * Total Submissions: 329.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 *
 *
 *
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 *
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以运用递归和迭代两种方法解决这个问题吗？
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        //return dfs(root->left, root->right); // 使用dfs递归的方式
        return check(root->left, root->right); // 使用迭代的方式
    }

    bool dfs(TreeNode* node_l, TreeNode* node_r)
    {
        if (!node_l && !node_r)
            return true;
        if (!node_l || !node_r)
            return false;
        return node_l->val == node_r->val && dfs(node_l->left, node_r->right)
            && dfs(node_l->right, node_r->left);
    }
    // 迭代的方法
    bool check(TreeNode* node_l, TreeNode* node_r)
    {
        queue<TreeNode*> q;
        q.push(node_l);
        q.push(node_r);

        while (!q.empty())
        {
            auto n1 = q.front(); q.pop();
            auto n2 = q.front(); q.pop();

            // 遇到了空节点先跳过
            if (!n1 && !n2)
                continue;
            if (!n1 || !n2)
                return false;
            if (n1->val != n2->val)
                return false;
            q.push(n1->left);
            q.push(n2->right);

            q.push(n1->right);
            q.push(n2->left);
        }
        return true;

    }
};
// @lc code=end

