/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (61.59%)
 * Likes:    622
 * Dislikes: 0
 * Total Accepted:    79.7K
 * Total Submissions: 129.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 *
 * k 是一个正整数，它的值小于或等于链表的长度。
 *
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 *
 *
 * 示例：
 *
 * 给你这个链表：1->2->3->4->5
 *
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 *
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 *
 *
 *
 * 说明：
 *
 *
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
    // 反转链表
    pair<ListNode *, ListNode *> reverse_list(ListNode *head, ListNode *tail)
    {
        auto prev = tail->next;
        auto p = head;
        while (prev != tail)
        {
            auto next_node = p->next;
            p->next = prev;
            prev = p;
            p = next_node;
        }
        return make_pair(tail, head);
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy_node = new ListNode(-1);
        dummy_node->next = head;
        auto pre = dummy_node;

        while (head)
        {
            auto tail = pre;
            // 查看是否有k个
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (tail == nullptr)
                    return dummy_node->next;
            }
            auto next_node = tail->next;
            auto reverse_result = reverse_list(head, tail);
            head = reverse_result.first;
            tail = reverse_result.second;
            // 重新接回链表
            pre->next = head;
            tail->next = next_node;
            pre = tail;
            head = tail->next;
        }
        return dummy_node->next;
    }
};
// @lc code=end
