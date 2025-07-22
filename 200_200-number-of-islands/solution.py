# Link: https://leetcode.com/problems/number-of-islands/description
# Description
# Given an
# m x n
# 2D binary grid
# grid
# which represents a map of
# '1'
# s (land) and
# '0'
# s (water), return
# the number of islands
# .
# An
# island
# is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
# Example 1:
# Input:
# grid = [
#   ["1","1","1","1","0"],
#   ["1","1","0","1","0"],
#   ["1","1","0","0","0"],
#   ["0","0","0","0","0"]
# ]
# Output:
# 1
# Example 2:
# Input:
# grid = [
#   ["1","1","0","0","0"],
#   ["1","1","0","0","0"],
#   ["0","0","1","0","0"],
#   ["0","0","0","1","1"]
# ]
# Output:
# 3
# Constraints:
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 300
# grid[i][j]
# is
# '0'
# or
# '1'
# .

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        ret = 0
        dirs = [[0,1],[1,0],[0,-1],[-1,0]]

        def helper(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != '1':
                return

            grid[i][j] = '0'

            for d in dirs:
                helper(i + d[0], j + d[1])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                   helper(i, j)
                   ret += 1
                
        return ret
            

