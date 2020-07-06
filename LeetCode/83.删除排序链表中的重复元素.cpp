/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (50.65%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    114.5K
 * Total Submissions: 225.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 * 示例 1:
 *
 * 输入: 1->1->2
 * 输出: 1->2
 *
 *
 * 示例 2:
 *
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
        auto now = head;
        while (now && now->next)
        {
            if (now->val == now->next->val)
            {
                now->next = now->next->next;
            }
            else
            {
                now = now->next;
            }
        }
        return head;
    }
    // 不那么简洁
    ListNode *deleteDuplicates_2(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto dummy_node = new ListNode(-1);
        dummy_node->next = head;
        auto ptr = head->next;
        while (ptr)
        {
            if (ptr->val == head->val)
            {
                ptr = ptr->next;
                if (!ptr)
                    head->next = ptr;
            }
            else
            {
                head->next = ptr;
                head = head->next;
                ptr = ptr->next;
            }
        }
        return dummy_node->next;
    }
    // 使用vector  效率很慢
    ListNode *deleteDuplicates_1(ListNode *head)
    {

        vector<int> value_set;
        while (head)
        {
            if (find(value_set.begin(), value_set.end(), head->val) == value_set.end())
                value_set.push_back(head->val);
            head = head->next;
        }
        auto dummy_node = new ListNode(-1);
        auto ptr = dummy_node;
        vector<int>::const_iterator begin = value_set.begin();
        while (begin != value_set.end())
        {
            ptr->next = new ListNode(*begin);
            ptr = ptr->next;
            begin++;
        }
        return dummy_node->next;
    }
};
// @lc code=end
