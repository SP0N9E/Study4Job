/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-07-20 15:02:39
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-07-20 15:14:47
 * @FilePath: \C++_Code\LeetCode\169.多数元素.cpp
 */
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (63.81%)
 * Likes:    670
 * Dislikes: 0
 * Total Accepted:    188.6K
 * Total Submissions: 295K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [3,2,3]
 * 输出: 3
 *
 * 示例 2:
 *
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 *
 *
 */

#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num : nums)
        {
            ++counts[num];
            if (counts[num] > cnt)
            {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};
// @lc code=end
