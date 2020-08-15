/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-15 17:39:04
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-15 18:06:48
 * @FilePath: \Study4Job\LeetCode\18.四数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (38.22%)
 * Likes:    538
 * Dislikes: 0
 * Total Accepted:    98.9K
 * Total Submissions: 258.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 *
 * 注意：
 *
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 *
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 *
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n - 3; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target)
                break;
            if (nums[first] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            for (int second = first + 1; second < n - 2; second++)
            {
                if (second > first + 1 && nums[second - 1] == nums[second])
                    continue;
                if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target)
                    break;
                if (nums[first] + nums[second] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                int left = second + 1;
                int right = n - 1;
                while (left < right)
                {
                    int sum = nums[left] + nums[right] + nums[second] + nums[first];
                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        res.push_back(vector<int>{nums[first], nums[second], nums[left], nums[right]});
                        do{left++;}
                        while (nums[left] == nums[left - 1] && left < right);
                        do{right--;}
                        while (nums[right] == nums[right + 1] && left < right);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
