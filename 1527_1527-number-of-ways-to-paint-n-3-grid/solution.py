# Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description
# Description
# You have a
# grid
# of size
# n x 3
# and you want to paint each cell of the grid with exactly one of the three colors:
# Red
# ,
# Yellow,
# or
# Green
# while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
# Given
# n
# the number of rows of the grid, return
# the number of ways
# you can paint this
# grid
# . As the answer may grow large, the answer
# must be
# computed modulo
# 10
# 9
# + 7
# .
# Example 1:
# Input:
# n = 1
# Output:
# 12
# Explanation:
# There are 12 possible way to paint the grid as shown.
# Example 2:
# Input:
# n = 5000
# Output:
# 30228214
# Constraints:
# n == grid.length
# 1 <= n <= 5000

class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        colors = [0,1,2]
        states = []

        def validState(state):
            for i in range(1, len(state)):
                if state[i] == state[i - 1]:
                    return False
                
            return True

        for state in product(colors, repeat = 3):
            if validState(state):
                states.append(state)

        mp = defaultdict(list)

        for a in states:
            for b in states:
                if all(x != y for x, y in zip(a,b)):
                    mp[a].append(b)

        dp = defaultdict(int)

        for state in states:
            dp[state] = 1

        for _ in range(1, n):
            temp = defaultdict(int)
            for current in states:
                for prev in mp[current]:
                    temp[current] = (temp[current] + dp[prev]) % MOD
            dp = temp

        return sum(dp.values()) % MOD
