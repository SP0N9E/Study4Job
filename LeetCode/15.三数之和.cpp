/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-11 14:10:05
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-11 14:15:54
 * @FilePath: \C++_Code\LeetCode\15.三数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (28.55%)
 * Likes:    2465
 * Dislikes: 0
 * Total Accepted:    297.5K
 * Total Submissions: 1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 * 示例：
 *
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 *
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int first = 0; first<n;first++)
        {
            if (first > 0 && nums[first-1] == nums[first])
                continue;
            int third = n-1;
            int target = -nums[first];
            for (int second = first+1; second<n; second++)
            {
                if (second>first+1 && nums[second] == nums[second-1])
                {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }
                if (second == third)
                    break;
                if (nums[second] + nums[third] == target) {
                    res.push_back({nums[first], nums[second], nums[third]});
                }

            }
        }
        return res;
    }
};
// @lc code=end
