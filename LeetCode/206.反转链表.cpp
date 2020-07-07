/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (69.56%)
 * Likes:    1068
 * Dislikes: 0
 * Total Accepted:    272.8K
 * Total Submissions: 391.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 *
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
class Solution {
public:
    ListNode* reverseList_1(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }

    // 双指针迭代版本
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = nullptr;
        ListNode* pre = head;
        while (pre!=nullptr)
        {
            auto next = pre->next;
            pre->next = cur;
            cur = pre;
            pre=next;

        }
        return cur;
    }
};
// @lc code=end

