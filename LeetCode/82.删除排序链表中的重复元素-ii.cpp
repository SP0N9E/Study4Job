/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (48.14%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    52.7K
 * Total Submissions: 109.3K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 *
 * 示例 1:
 *
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 *
 *
 * 示例 2:
 *
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy_node = new ListNode(-1);
        dummy_node->next = head;
        auto pre = dummy_node;
        // 循环
        while (head)
        {
            auto node = head->next;
            if (node == nullptr)
                break;
            // 找到重复节点末尾的下一个有效节点
            while (node != nullptr && head->val == node->val)
            {
                node = node->next;
            }
            // 判断在上个while循环中有没有找到节点
            if (head->next != node)
            {
                head = node;
                pre->next = head;
            }
            else
            {
                head = head->next;
                pre = pre->next;
            }
        }
        // 释放内存
        auto res = dummy_node->next;
        delete dummy_node;
        dummy_node = nullptr;

        return res;
    }
};
// @lc code=end
