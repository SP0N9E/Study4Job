/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.68%)
 * Likes:    4544
 * Dislikes: 0
 * Total Accepted:    467.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
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
    // 不对齐链表
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *res = new ListNode(-1); // 返回结果
        ListNode* res_ptr = res;
        int if_sum_over_10 = 0;
        int tmp_sum = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            tmp_sum = 0;
            if (l1!=nullptr)
            {
                tmp_sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=nullptr)
            {
                tmp_sum += l2->val;
                l2=l2->next;
            }
            tmp_sum+=if_sum_over_10;
            res_ptr->next = new ListNode(tmp_sum%10);
            res_ptr = res_ptr->next;
            if_sum_over_10 = tmp_sum>=10?1:0;
        }
        if (if_sum_over_10)
            res_ptr->next = new ListNode(1);

        return res->next;
    }
    // 补全对齐链表的做法
    ListNode *addTwoNumbers_1(ListNode *l1, ListNode *l2)
    {
        int len1 = 1, len2 = 1;
        ListNode *p = l1;
        ListNode *q = l2;
        while (p->next != nullptr)
        {
            len1++;
            p = p->next;
        }
        while (q->next != nullptr)
        {
            len2++;
            q = q->next;
        }

        // l1长 补全l2
        if (len1 > len2)
        {
            for (int i = 0; i < len1 - len2; ++i)
            {
                q->next = new ListNode(0);
                q = q->next;
            }
        }
        else if (len1 < len2) // l2长 补全l1
        {
            for (int i = 0; i < len2 - len1; ++i)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }

        p = l1;
        q = l2;
        int if_sum_over_10 = 0;           // 是否需要进位操作 0代表不需要进位 1需要进位
        ListNode *res = new ListNode(-1); // 最终结果
        ListNode *res_ptr = res;          // 结果链表游动的指针
        int tmp_sum = 0;
        while (p != nullptr && q != nullptr)
        {
            tmp_sum = if_sum_over_10 + p->val + q->val;
            res_ptr->next = new ListNode(tmp_sum % 10);
            if_sum_over_10 = tmp_sum >= 10 ? 1 : 0;
            res_ptr = res_ptr->next;
            p = p->next;
            q = q->next;
        }

        // 要是最后还有进位
        if (if_sum_over_10)
        {
            res_ptr->next = new ListNode(1);
            res_ptr = res_ptr->next;
        }
        return res->next;
    }
};
// @lc code=end

int main()
{
    Solution s;
    ListNode *test1 = new ListNode(1);
    ListNode *test2 = new ListNode(0);
    test1->next = new ListNode(8);

    auto res = s.addTwoNumbers(test1, test2);
    while (res != nullptr)
    {
        cout << res->val << " ";
    }
}