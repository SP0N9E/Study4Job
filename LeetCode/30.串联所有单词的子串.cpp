/*
 * @Author: SP0N9E
 * @Description: Edit
 * @Date: 2020-08-20 21:25:58
 * @LastEditors: SP0N9E
 * @LastEditTime: 2020-08-20 21:52:09
 * @FilePath: \C++_Code\LeetCode\30.串联所有单词的子串.cpp
 */
/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (31.51%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 132.5K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 *
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 *
 *
 *
 * 示例 1：
 *
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 *
 *
 * 示例 2：
 *
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
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
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.size() == 0)//判断words为空,因为下面用到了words[0]
            return ret;

        int word_size = words[0].size();
        int word_num = words.size();

        unordered_map<string,int> m1;//构造hashmap
        for(int i=0;i<word_num;i++)
            m1[words[i]]++;

        unordered_map<string,int> m2;
        for(int i=0; (i + word_size * word_num) <= s.size() ; i++){//截取的s符合题意
            int j = 0;
            for(j=i;j < (i + word_size * word_num) ; j=j+word_size){//分段判断
                string temp_str = s.substr(j,word_size);
                if(m1[temp_str] == 0){//m1中没有截取的串，直接跳出
                    break;
                }else{
                    m2[temp_str]++;
                    if(m1[temp_str] < m2[temp_str])//重复次数过多，也跳出
                        break;
                }
            }

            if(j == (i + word_size * word_num))//每一段都符合，则加入答案
                ret.push_back(i);

            m2.clear();//清空m2
        }
        return ret;
    }
};
// @lc code=end

