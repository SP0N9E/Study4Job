/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (40.41%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    69.8K
 * Total Submissions: 172.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 *
 * 示例 1:
 *
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 *
 *
 * 示例 2:
 *
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        auto head_ptr = head;
        ListNode *pre = head;
        if (head == nullptr)
            return head;
        int length = 1;
        while (pre->next != nullptr)
        {
            // if (head->next == nullptr)
            //     pre = head;
            // head = head->next;
            pre=pre->next;
            ++length;
        }

        // 连成一个环
        pre->next = head_ptr;
        // 计算要往前多少步
        int forward_step = judgeForwardStep(length, k);
        for (int i = 0; i < forward_step; i++)
        {
            //head_ptr = head_ptr->next;
            pre = pre->next;
        }
        head_ptr = pre->next;
        pre->next = nullptr;
        return head_ptr;
    }

    inline int judgeForwardStep(int length, int k)
    {
        return length - (k - (k / length) * length);// 运行时间更短
        //return length - k % length; // 运行时间更长
    }
};
// @lc code=end
