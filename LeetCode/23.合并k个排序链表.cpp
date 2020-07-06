/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (52.09%)
 * Likes:    772
 * Dislikes: 0
 * Total Accepted:    139K
 * Total Submissions: 266.5K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    struct NodeVal
    {
        int val;
        ListNode* ptr;
        bool operator < (const NodeVal& nodeval) const {
            return val > nodeval.val;
        }
    };

    priority_queue<NodeVal> q;
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        for (auto p:lists)
        {
            if (p)
                q.push({p->val, p});
        }
        ListNode* res = new ListNode(-1);
        ListNode* res_ptr = res;
        while(!q.empty())
        {
            auto tmp_node = q.top();
            q.pop();
            res_ptr->next = tmp_node.ptr;
            res_ptr = res_ptr->next;
            if (tmp_node.ptr->next)
                q.push({tmp_node.ptr->next->val, tmp_node.ptr->next});
        }
        return res->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        return mergeTwoLists_1(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode *mergeKLists_2(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode *mergeKLists_1(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        for (int i = 0; i < lists.size() - 1; i++)
        {
            lists[i + 1] = mergeTwoLists_1(lists[i], lists[i + 1]);
        }
        return lists[lists.size() - 1];
    }

    ListNode *mergeTwoLists_1(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(-1); // dummy node
        auto res_node = res;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val)
            {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }

        res->next = l1 == nullptr ? l2 : l1;
        return res_node->next;
    }
};
// @lc code=end
