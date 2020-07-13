/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (65.95%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 29.3K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 *
 * 找到所有出现两次的元素。
 *
 * 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 *
 * 示例：
 *
 *
 * 输入:
 * [4,3,2,7,8,2,3,1]
 *
 * 输出:
 * [2,3]
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
    // O(n)时间 不需要额外空间
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> twice = {};
        nums.push_back(1);
        int temp = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            nums[i]>0 ? temp=nums[i] : temp = nums[i]*(-1);
            if(nums[temp]>0)
                nums[temp] = (-1)*nums[temp];
            else
                twice.push_back(temp);
        }
        return twice;
    }
    // 哈希表处理 O(n)时间 O(n)空间
    vector<int> findDuplicates_2(vector<int> &nums)
    {
        vector<int> hash(nums.size()+1, 0);
        vector<int> res;
        for (int i = 0; i<nums.size(); i++)
        {
            if (hash[nums[i]] != 0)
                res.push_back(nums[i]);
            else
            {
                hash[nums[i]]++;
            }

        }
        return res;
    }
    // 排序之后遍历 O(nlogn)时间
    vector<int> findDuplicates_1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
