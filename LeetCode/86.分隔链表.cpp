/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (58.34%)
 * Likes:    222
 * Dislikes: 0
 * Total Accepted:    42.1K
 * Total Submissions: 72.1K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 *
 * 你应当保留两个分区中每个节点的初始相对位置。
 *
 * 示例:
 *
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return head;
        ListNode* before  = new ListNode(-1);
        auto after = new ListNode(-1);
        auto p1 = before;
        auto p2 = after;

        while (head)
        {
            if (head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
                head = head->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
                head = head->next;
            }

        }
        p2->next = nullptr;
        p1->next = after->next;
        return before->next;
    }
};
// @lc code=end

