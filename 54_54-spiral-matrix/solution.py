# Link: https://leetcode.com/problems/spiral-matrix/description
# Description
# Given an
# m x n
# matrix
# , return
# all elements of the
# matrix
# in spiral order
# .
# Example 1:
# Input:
# matrix = [[1,2,3],[4,5,6],[7,8,9]]
# Output:
# [1,2,3,6,9,8,7,4,5]
# Example 2:
# Input:
# matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
# Output:
# [1,2,3,4,8,12,11,10,9,5,6,7]
# Constraints:
# m == matrix.length
# n == matrix[i].length
# 1 <= m, n <= 10
# -100 <= matrix[i][j] <= 100

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ret = []
        m, n = len(matrix), len(matrix[0])  
        r, c, dir = 0, -1, 1

        while m > 0 and n > 0:
            for i in range(n):
                c += dir
                ret.append(matrix[r][c])
            m -= 1
            for i in range(m):
                r += dir
                ret.append(matrix[r][c])
            n -= 1

            dir *= -1
        
        return ret
