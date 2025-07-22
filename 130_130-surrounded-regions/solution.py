# Link: https://leetcode.com/problems/surrounded-regions/description
# Description
# You are given an
# m x n
# matrix
# board
# containing
# letters
# 'X'
# and
# 'O'
# ,
# capture regions
# that are
# surrounded
# :
# Connect
# : A cell is connected to adjacent cells horizontally or vertically.
# Region
# : To form a region
# connect every
# 'O'
# cell.
# Surround
# : The region is surrounded with
# 'X'
# cells if you can
# connect the region
# with
# 'X'
# cells and none of the region cells are on the edge of the
# board
# .
# To capture a
# surrounded region
# , replace all
# 'O'
# s with
# 'X'
# s
# in-place
# within the original board. You do not need to return anything.
# Example 1:
# Input:
# board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
# Output:
# [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
# Explanation:
# In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
# Example 2:
# Input:
# board = [["X"]]
# Output:
# [["X"]]
# Constraints:
# m == board.length
# n == board[i].length
# 1 <= m, n <= 200
# board[i][j]
# is
# 'X'
# or
# 'O'
# .

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])

        if m <= 2 or n <= 2:
            return

        def dfs(i, j):
            if board[i][j] == 'O':
                board[i][j] = 'S'
            else:
                return
            for d in [[0,1],[1,0],[0,-1],[-1,0]]:
                if 0 <= i + d[0] < m and 0 <= j + d[1] < n:
                    dfs(i + d[0], j + d[1])

        for i in range(n):
            if board[0][i] == 'O':
                dfs(0,i)
            if board[m-1][i] == 'O':
                dfs(m-1,i)

        for i in range(m):
            if board[i][0] == 'O':
                dfs(i, 0)
            if board[i][n-1] == 'O':
                dfs(i, n-1)

        for i in range(1, m-1):
            for j in range(1, n-1):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'S':
                    board[i][j] = 'O'



        
