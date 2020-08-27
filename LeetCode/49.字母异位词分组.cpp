/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-27 15:53:48
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-27 16:06:27
 * @FilePath: \C++_Code\LeetCode\49.字母异位词分组.cpp
 */
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.03%)
 * Likes:    447
 * Dislikes: 0
 * Total Accepted:    100.3K
 * Total Submissions: 158.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 *
 * 示例:
 *
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * 说明：
 *
 *
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
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
#include <assert.h>
#include <string>
#include <memory>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string s : strs)
        {
            auto t = s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }

        for (auto tmp:m)
        {
            res.push_back(tmp.second);
        }
        return res;
    }
};
// @lc code=end
