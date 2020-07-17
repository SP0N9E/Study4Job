/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (51.05%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    59.9K
 * Total Submissions: 117.2K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 *
 * 请找出其中最小的元素。
 *
 * 你可以假设数组中不存在重复元素。
 *
 * 示例 1:
 *
 * 输入: [3,4,5,1,2]
 * 输出: 1
 *
 * 示例 2:
 *
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
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
class Solution {
public:
    // 二分查找
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int idx = binarySearch(nums);
        return nums[idx];
    }

    int binarySearch(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (nums[left] >= nums[right])
        {
            if (right - left == 1)
            {
                mid = right;
                break;
            }

            mid = left + (right - left) / 2;


            if (nums[mid] >= nums[left])
            {
                left = mid;
            }
            else if (nums[mid] <= nums[right])
            {
                right = mid;
            }


        }
        return mid;
    }
};
// @lc code=end

