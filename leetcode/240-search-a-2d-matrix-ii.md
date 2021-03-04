# 搜索二维矩阵 II

## 题目

[原题地址](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

(下面用剑指Offer中的原题作为示例)
[地址](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

**示例:**

现有矩阵 matrix 如下：

```markdown
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

给定 target = 5，返回 true。

给定 target = 20，返回 false。

**限制：**

- 0 <= n <= 1000
- 0 <= m <= 1000

## 题解

二维数组的行和列中的元素都是升序排列，观察后，不难发现一个规律，那就是**每一个数都比左边的数大，比下面的数小**。那么我们可以从右上角开始遍历，当target比当前数小时，列指针往左移动；当target比当前数大时，行指针往下移动。直到找到target，或其中一个指针不能再移动为止。

## 代码

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int r = 0, c = cols - 1;

        while(r < rows && c >= 0){
            int tmp = matrix[r][c];

            if(target > tmp) r++;
            else if(target < tmp) c--;
            else return true;
        }

        return false;
    }
};
```