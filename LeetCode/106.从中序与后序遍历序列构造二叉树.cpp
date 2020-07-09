/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (68.83%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 60.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 *
 * 返回如下的二叉树：
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *mybuildTree(const vector<int> &inorder, const vector<int> &postorder,
                          int in_left, int in_right, int post_left, int post_right)
    {
        if (post_left > post_right)
            return nullptr;

        int post_root = post_left;
        int in_root = index[postorder[post_root]];

        // 左子树的个数
        int subtree_left_num = in_root - in_left;
        // 构建根节点
        TreeNode* root = new TreeNode(postorder[post_root]);
        root->left = mybuildTree(inorder, postorder, in_left, in_root-1, post_right - subtree_left_num+1, post_right);
        root->right = mybuildTree(inorder, postorder, in_root+1, in_right, post_left+1, post_right-subtree_left_num);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = postorder.size();
        for (int i = 0; i < size; i++)
        {
            index[inorder[i]] = i;
        }
        return mybuildTree(inorder, vector<int>(postorder.rbegin(), postorder.rend()), 0, size - 1, 0, size - 1);
    }
};
// @lc code=end
