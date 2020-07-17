/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (54.01%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    37.7K
 * Total Submissions: 69.5K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 *
 * 要求返回这个链表的 深拷贝。 
 *
 * 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 *
 *
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 *
 * 示例 4：
 *
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -10000 <= Node.val <= 10000
 * Node.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        cloneNodes(head);
        cloneRandomNodes(head);
        return reconnectNode(head);
    }

    // 复制节点。A->A'->B->B'->…
    void cloneNodes(Node *head)
    {
        auto h_ptr = head;
        while (h_ptr)
        {
            auto clone_node = new Node(0);
            clone_node->val = h_ptr->val;
            clone_node->next = h_ptr->next;

            h_ptr->next = clone_node;
            h_ptr = clone_node->next;
        }
    }

    // 复制随机节点
    void cloneRandomNodes(Node *head)
    {
        auto node = head;
        while (node)
        {
            auto clone_node = node->next;
            if (node->random != nullptr)
                clone_node->random = node->random->next;

            node = clone_node->next;
        }
    }

    // 将链表分成两部分
    Node *reconnectNode(Node *head)
    {
        auto node_ptr = head;
        Node *originHead = nullptr;
        Node *cloneHead = nullptr;
        Node *cloneNode = nullptr;

        if (node_ptr!=nullptr)
        {
            cloneHead = cloneNode = node_ptr->next;
            node_ptr->next = cloneNode->next;
            node_ptr = node_ptr->next;
        }

        while (node_ptr!=nullptr)
        {
            cloneNode->next = node_ptr->next;
            cloneNode = cloneNode->next;
            node_ptr->next = cloneNode->next;
            node_ptr = node_ptr->next;
        }
        return cloneHead;
    }
};
// @lc code=end
