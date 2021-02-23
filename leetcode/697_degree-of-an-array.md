# 数组的度

## 题目

[原题地址](https://leetcode-cn.com/problems/degree-of-an-array/)

给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

**示例 1：**

```markdown
输入：[1, 2, 2, 3, 1]

输出：2

解释：
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
```

**示例 2：**

```markdown
输入：  [1,2,2,3,1,4,2]  
输出：  6
```

**提示：**

- nums.length 在1到 50,000 区间范围内。
- nums[i] 是一个在 0 到 49,999 范围内的整数。

## 题解

首先理解题中“度”的定义：任一元素在数组中出现频数的最大值。也就是说，整个数组中，某个元素出现的次数最多，那么他的出现次数就是度。然后我们需要找出相同大小的度的最短连续子数组，那么很显然，从那个频次最大的元素的第一次出现的位置到最后一次出现的位置，组成的连续子数组，就是所求的子数组。

举个例子：
[1,2,2,3,1,4,2] 中，2的出现频次最多，一共3次，那么所求的子数组必须最少包含3个2，自然而然，恰好包含3个2的连续子数组就是所求子数组，即[2,2,3,1,4,2]，长度为6。

我们需要维护一个哈希表，其中的键就是数组中的元素，值是一个数组，用于记录该元素的出现频次，第一次出现的位置，最后一次出现的位置。首先遍历数组建立该哈希表，然后再遍历哈希表找出频次最大的元素，再将最后一次出现的位置减去第一次出现的位置，再加1，即是所要找的最短连续子数组的长度。

## 代码

```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // num: <count, first position, last position>
        unordered_map<int, vector<int>> mp;  
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            } else {
                mp[nums[i]] = {1, i, i};   
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto& [_, vec] : mp) {
            if (maxNum < vec[0]) {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            } else if (maxNum == vec[0]) {
                int tmpLen = vec[2] - vec[1] + 1;
                if (minLen > tmpLen) 
                    minLen = tmpLen;
            }
        }
        return minLen;
    }
};
```
