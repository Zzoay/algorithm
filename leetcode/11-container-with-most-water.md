
# 盛最多水的容器

## 题目

[原题地址](https://leetcode-cn.com/problems/container-with-most-water/)

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

**说明：**你不能倾斜容器。

**示例 1：**

<img src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg" alt="leetcode" style="zoom:67%;" />

```markdown
输入：[1,8,6,2,5,4,8,3,7]
输出：49 

解释：
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。
在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```

**示例 2：**

```markdown
输入：height = [1,1]
输出：1
```

**示例 3：**

```markdown
输入：height = [4,3,2,1,4]
输出：16
```

**示例 4：**

```markdown
输入：height = [1,2,1]
输出：2
```

**提示：**

- n = height.length
- 2 <= n <= 3 * 104
- 0 <= height[i] <= 3 * 104

## 题解

一道非常有趣的题目，其实可以用**双指针**来解决。一开始，两个指针left和right分别在数组两端，此时，可以计算当前能盛的水**S**：
$$
S = (right-left)*min(height[right], height[left])
$$
然后，我们移动其中一个指针，很显然，应当移动较矮的那个，因为能盛的水取决于矮的那端，移动之后，继续计算**S**，与前面的S比较，取较大者。重复上述步骤，直到左右指针相遇。

## 代码

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len - 1;
        int area = 0;
        
        while(left != right){
            int lHight = height[left];
            int rHight = height[right];
            int tmpArea = min(lHight, rHight)*(right-left);

            if(area < tmpArea) area = tmpArea;

            if(lHight < rHight) left++;
            else right--;
        }

        return area;
    }
};
```
