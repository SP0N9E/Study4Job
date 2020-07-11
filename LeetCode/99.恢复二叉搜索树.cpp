/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (57.44%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 36K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 *
 * 请在不改变其结构的情况下，恢复这棵树。
 *
 * 示例 1:
 *
 * 输入: [1,3,null,null,2]
 *
 * 1
 * /
 * 3
 * \
 * 2
 *
 * 输出: [3,1,null,null,2]
 *
 * 3
 * /
 * 1
 * \
 * 2
 *
 *
 * 示例 2:
 *
 * 输入: [3,1,4,null,null,2]
 *
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 *
 * 输出: [2,1,4,null,null,3]
 *
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 *
 * 进阶:
 *
 *
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void recoverHelper(TreeNode *root, int count, int first, int second)
    {
        if (root != nullptr)
        {
            if (root->val == first)
            {
                root->val = second;
                if (--count == 0)
                    return;
            }
            else if (root->val == second)
            {
                root->val = first;
                if (--count == 0)
                    return;
            }
            recoverHelper(root->left, count, first, second);
            recoverHelper(root->right, count, first, second);
        }
    }

    void recoverTree(TreeNode *root)
    {
        if (!root->left && !root->right)
            return;
        if (!root)
            return;
        //auto swap_pair = inorder(root);
        auto swap_pair = MorrisInorder(root);
        recoverHelper(root, 2, swap_pair.first, swap_pair.second);
    }

    // 中序遍历寻找两个位置错误的数字
    pair<int, int> inorder(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> record;
        //s.push(root);
        int pre = -1;
        while (!s.empty() || root)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            record.push_back(root->val);
            root = root->right;
        }

        return findSwapNumber(record);
    }
    // 在vector中找到两个位置错误的数字
    pair<int, int> findSwapNumber(const vector<int> &record)
    {
        int first = -1, second = -1;
        int pre = record[0];
        int cur;
        for (int i = 1; i < record.size(); i++)
        {
            cur = record[i];
            if (pre > cur)
            {
                if (first == -1)
                    first = pre;
                second = cur;
            }
            pre = record[i];
        }
        return pair<int, int>(first, second);
    }


    // // morris中序遍历
    // pair<int, int> MorrisInorder(TreeNode *root)
    // {
    //     vector<int> record;
    //     auto cur = root;
    //     TreeNode* pre;
    //     while (cur != nullptr)
    //     {
    //         if (cur->left != nullptr) // 左子树不为空 进入左子树
    //         {
    //             // 寻找precessor
    //             auto precessor = cur->left;
    //             while(precessor->right!=nullptr && precessor->right!=cur)
    //             {
    //                 precessor = precessor->right;
    //             }
    //             // 前驱指向自己
    //             if (precessor->right == cur)
    //             {
    //                 // 断开连接
    //                 precessor->right == nullptr;
    //                 pre = cur;
    //                 cur = cur->right;
    //             }
    //             else // 前驱没有指向自己  左边没有遍历
    //             {
    //                 precessor->right = cur;
    //                 cur = cur->left;
    //             }
    //         }
    //         else // 左子树为空 进入右节点
    //         {
    //             record.push_back(cur->val);
    //             pre = cur;
    //             cur = cur->right;
    //         }

    //     }

    //     return findSwapNumber(record);
    // }
};
// @lc code=end
