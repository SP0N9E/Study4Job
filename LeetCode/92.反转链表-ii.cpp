/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (50.47%)
 * Likes:    416
 * Dislikes: 0
 * Total Accepted:    58.8K
 * Total Submissions: 116.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode *successor;
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }
        auto last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
    // 递归的方法
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 如果m为1，相当于从头开始反转n个点
        if (m == 1)
        {
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
    // 迭代的方法
    ListNode *reverseBetween_1(ListNode *head, int m, int n)
    {
        if (head == nullptr || m == n)
            return head;
        ListNode *dummy_node = new ListNode(-1);
        dummy_node->next = head;
        auto pre = dummy_node;
        int len = 1;
        // 找到m对应的节点
        while (len < m)
        {
            len++;
            head = head->next;
            pre = pre->next;
        }
        auto cur = head;
        auto next = cur->next;
        // 将后面的节点指向前面的节点
        while (len < n)
        {
            len++;
            auto tmp_next = next->next;
            next->next = cur;
            cur = next;
            next = tmp_next;
        }
        pre->next = cur;
        head->next = next;

        auto res = dummy_node->next;
        // 释放指针
        delete dummy_node;
        dummy_node = nullptr;

        return res;
    }
};
// @lc code=end
