/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end() && m[target-nums[i]] != i)
                return {i, m[target-nums[i]]};
        }
        return {};
    }

    vector<int> twoSum_OneHash(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
                return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }

    vector<int> twoSum_BruteForce(vector<int>& nums, int target) {
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();
        vector<int> res;
        for (int i = 0; i<nums.size(); i++)
        {
            int now = nums[i];
            int complement = target - now;
            auto idx = find(begin, end, complement);
            if (idx != end && (idx-begin) != i)
            {
                res.push_back(i);
                res.push_back(idx - begin);
                return res;
            }
        }
        return res;
    }
};
// @lc code=end

