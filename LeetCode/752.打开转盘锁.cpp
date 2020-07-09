/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 *
 * https://leetcode-cn.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (48.86%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 35.8K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8',
 * '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
 *
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
 *
 * 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
 *
 * 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * 输出：6
 * 解释：
 * 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
 * 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
 * 因为当拨动到 "0102" 时这个锁就会被锁定。
 *
 *
 * 示例 2:
 *
 *
 * 输入: deadends = ["8888"], target = "0009"
 * 输出：1
 * 解释：
 * 把最后一位反向旋转一次即可 "0000" -> "0009"。
 *
 *
 * 示例 3:
 *
 *
 * 输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * 输出：-1
 * 解释：
 * 无法旋转到目标数字且不被锁定。
 *
 *
 * 示例 4:
 *
 *
 * 输入: deadends = ["0000"], target = "8888"
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 死亡列表 deadends 的长度范围为 [1, 500]。
 * 目标数字 target 不会在 deadends 之中。
 * 每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
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
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    string stringUp(string s, int j)
    {
        if (s[j] == '9')
            s[j] = '0';
        else
        {
            s[j] += '1' - '0';
        }
        return s;
    }

    string stringDown(string s, int j)
    {
        if (s[j] == '0')
            s[j] = '9';
        else
        {
            s[j] -= '1' - '0';
        }
        return s;
    }
    // 单向BFS
    int openLock_1(vector<string> &deadends, string target)
    {
        // 存储已经访问过的密码组合
        set<string> visited;
        // 存储死亡数字
        set<string> deads;
        for (auto s : deadends)
        {
            deads.insert(s);
        }
        queue<string> q;
        int step = 0;
        q.push("0000");
        visited.insert("0000");

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                // 如果和target相等 返回step
                if (node == target)
                    return step;
                // 判断是否访问到死亡数字
                if (deads.find(node) != deads.end())
                    continue;
                // 将一个节点的子节点加入队列
                for (int j = 0; j < 4; j++)
                {
                    string up = stringUp(node, j);
                    // 没有添加过
                    if (visited.find(up) == visited.end())
                    {
                        visited.insert(up);
                        q.push(up);
                    }

                    string down = stringDown(node, j);
                    // 没有添加过
                    if (visited.find(down) == visited.end())
                    {
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    // 双向BFS
    int openLock(vector<string> &deadends, string target)
    {
        set<string> deads;
        for (auto s : deadends)
            deads.insert(s);
        // 初始节点和目标节点
        set<string> q1;
        set<string> q2;
        set<string> visited;

        int step = 0;
        q1.insert("0000");
        q2.insert(target);

        while (!q1.empty() && !q2.empty())
        {
            set<string> temp;
            if (q1.size() > q2.size())
                swap(q1, q2);

            for (auto node : q1)
            {
                if (deads.find(node) != deads.end())
                    continue;
                if (q2.find(node) != q2.end())
                    return step;
                visited.insert(node);

                // 将一个节点的子节点加入队列
                for (int i = 0; i < 4; i++)
                {
                    auto up = stringUp(node, i);
                    if (visited.find(up) == visited.end())
                        temp.insert(up);
                    auto down = stringDown(node, i);
                    if (visited.find(down) == visited.end())
                        temp.insert(down);
                }
            }
            step++;
            // 交换q1 q2
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};
// @lc code=end
