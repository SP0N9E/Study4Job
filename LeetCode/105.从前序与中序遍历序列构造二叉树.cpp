/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.34%)
 * Likes:    557
 * Dislikes: 0
 * Total Accepted:    92.7K
 * Total Submissions: 137.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 * 返回如下的二叉树：
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
private:
    unordered_map<int, int> index;

public:
    TreeNode *mybuildTree(const vector<int> &preorder, const vector<int> &inorder,
                          int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right)
            return nullptr;

        int pre_root = pre_left;
        int in_root = index[preorder[pre_left]];

        // 左子树的数目
        int subtree_left_num = in_root - in_left;
        // 构建根节点
        TreeNode *root = new TreeNode(inorder[in_root]);
        root->left = mybuildTree(preorder, inorder, pre_left + 1, pre_left + subtree_left_num, in_left, in_root - 1);
        root->right = mybuildTree(preorder, inorder, pre_left + subtree_left_num + 1, pre_right, in_root + 1, in_right);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int size = preorder.size();
        for (int i = 0; i < size; i++)
        {
            index[inorder[i]] = i;
        }
        return mybuildTree(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};
// @lc code=end
