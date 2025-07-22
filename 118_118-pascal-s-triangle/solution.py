# Link: https://leetcode.com/problems/pascals-triangle/description
# Description
# Given an integer
# numRows
# , return the first numRows of
# Pascal's triangle
# .
# In
# Pascal's triangle
# , each number is the sum of the two numbers directly above it as shown:
# Example 1:
# Input:
# numRows = 5
# Output:
# [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
# Example 2:
# Input:
# numRows = 1
# Output:
# [[1]]
# Constraints:
# 1 <= numRows <= 30

class Solution:
    def generate(self, n: int) -> List[List[int]]:
        ret = [[1] * i for i in range(1, n + 1)]

        if n <= 2:
            return ret

        for i in range(2, n):
            for j in range(1, i):
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j]

        return ret


