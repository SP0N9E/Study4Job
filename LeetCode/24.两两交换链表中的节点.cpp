/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (66.00%)
 * Likes:    541
 * Dislikes: 0
 * Total Accepted:    120.5K
 * Total Submissions: 182.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例:
 *
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 *
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
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
    // 递归
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        // head的下一个节点 head与second需要进行交换
        auto second = head->next;
        // second的下个节点 暂时保存
        auto third = second->next;
        second->next = head;
        // head的下个节点为third节点经过交换之后的节点
        head->next = swapPairs(third);
        return second;
    }

    // 常规迭代
    ListNode *swapPairs_1(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy_node = new ListNode(-1);
        auto pre = head;
        auto now = head->next;
        auto pre_head = dummy_node;
        // 判断是否需要进行交换
        int if_pair_count = 2;

        while (now != nullptr)
        {
            if (if_pair_count == 2)
            {
                pre->next = now->next;
                now->next = pre;
                pre_head->next = now;
                if_pair_count = 1;
                // 交换now和pre
                now = pre;
                pre = pre_head->next;
            }
            else
            {
                if_pair_count++;
            }
            // 更新节点
            now = now->next;
            pre = pre->next;
            pre_head = pre_head->next;
        }
        return dummy_node->next;
    }
};
// @lc code=end
