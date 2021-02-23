# 优美子数组

## 题目

[原题地址](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/)

给你一个整数数组 nums 和一个整数 k。

如果某个连续子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

**示例 1：**

```markdown
输入： nums = [1,1,2,1,1], k = 3
输出： 2
解释： 包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
```

**示例 2：**

```markdown
输入： nums = [2,4,6], k = 1
输出： 0
解释： 数列中不包含任何奇数，所以不存在优美子数组。
```

**示例 3：**

```markdown
输入： nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出： 16
```

**提示：**

- 1 <= nums.length <= 50000
- 1 <= nums[i] <= 10^5
- 1 <= k <= nums.length

## 题解

题目中有两大关键信息：

- 恰好包含k个奇数
- 连续子数组

那么可以用**前缀和**来求解此题，只需在遍历数组时，计算第i个元素的前缀的奇数个数和sum[i]，同时维护一个哈希表(对于整数而言可以用数组代替)，记录满足相应前缀和的元素的次数，即可求解满足条件的区间个数，即是优美子数组的个数。

## 代码

```c++
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> mp;   
        int cnt = 0, ans = 0;
        mp.resize(nums.size() + 2, 0);
        mp[0] = 1;
        for(auto num:nums){
            cnt += num & 1;  // count odd
            mp[cnt] ++; 
            if(cnt >= k) ans += mp[cnt-k];
        }
        return ans;
    }
};
```
