/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (69.37%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 71.4K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为一个单链表。
 *
 *
 *
 * 例如，给定二叉树
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 *
 * 将其展开为：
 *
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 反向后序遍历
    vector<TreeNode *> reverse_postorder(TreeNode *root)
    {
        vector<TreeNode *> res;
        if (root == nullptr)
            return res;
        stack<TreeNode *> s;
        auto p = root;
        while (!s.empty() || p)
        {
            while (p)
            {
                res.push_back(p);
                s.push(p->right);
                p = p->left;
            }
            p = s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // 迭代后序遍历更改指向
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        auto vec = reverse_postorder(root);
        auto pre = vec[0];
        TreeNode* cur;
        for (int i = 1; i<vec.size(); i++)
        {
            cur = vec[i];
            cur->right = pre;
            cur->left = nullptr;
            pre = vec[i];
        }
        return;
    }

    TreeNode *pre = nullptr;
    // 递归后序遍历更改指向
    void flatten_2(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }

    //
    void flatten_1(TreeNode *root)
    {
        while (root != nullptr)
        {
            if (root->left == nullptr) // 没有左节点
            {
                root = root->right;
            }
            else
            {
                // 找到左子树最右节点
                TreeNode *tmp = root->left;
                while (tmp->right != nullptr)
                {
                    tmp = tmp->right;
                }
                tmp->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};
// @lc code=end
