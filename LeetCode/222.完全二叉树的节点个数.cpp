/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-31 22:49:23
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-01 11:37:48
 * @FilePath: \C++_Code\LeetCode\222.完全二叉树的节点个数.cpp
 */
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (70.80%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    27.5K
 * Total Submissions: 38.7K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给出一个完全二叉树，求出该树的节点个数。
 *
 * 说明：
 *
 *
 * 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 *
 * 示例:
 *
 * 输入:
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 *
 * 输出: 6
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
#include <assert.h>
#include <string>
#include <memory>
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
    // 递归
    int countNodes_1(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    // 求二叉树的深度
    int countLevels(TreeNode* root) {
    	int levels = 0;
    	while (root) {
    	    root = root->left; levels += 1;
        }
        return levels;
    }

    /*
    * 功能： 判断最后一层第index个索引是否存在
    * root： 二叉树根节点
    * index：判断最后一层索引为index的节点是否存在, 索引范围是[1, 2^depth]
    * depth：倒数第二层的深度, 这是因为满二叉树最后一层的节点数等于 2^depth
    */
    bool is_exist(TreeNode* root, int index, int depth) {
        TreeNode* node = root;
        while (depth) {
            // 最后一层分界线
            int mid = ((1 << depth) >> 1);
            if (index > mid) {
                // 如果在右子树，需要更新索引值
                index -= mid;
                node = node->right;
            }
            else {
                node = node->left;
            }
            depth -= 1;
        }
        return node != nullptr;
    }

    int countNodes(TreeNode* root) {
        // 3. 二分查找
        if (root == nullptr) return 0;
        // 二叉树深度
        int depth = countLevels(root);
        // 倒数第二层深度
        int depth_prev = depth - 1;

        int start = 1, end = (1 << depth_prev), mid = 0;
        while (start <= end) {
            mid = start + ((end - start) >> 1);
            if (is_exist(root, mid, depth_prev)) start = mid + 1;
            else end = mid - 1;
        }
        // start - 1为最后一层节点数
        int ret = (1 << depth_prev) - 1 + start - 1;
        return ret;
    }

};
// @lc code=end
