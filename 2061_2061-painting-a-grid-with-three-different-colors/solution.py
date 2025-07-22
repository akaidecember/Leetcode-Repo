# Link: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description
# Description
# You are given two integers
# m
# and
# n
# . Consider an
# m x n
# grid where each cell is initially white. You can paint each cell
# red
# ,
# green
# , or
# blue
# . All cells
# must
# be painted.
# Return
# the number of ways to color the grid with
# no two adjacent cells having the same color
# . Since the answer can be very large, return it
# modulo
# 10
# 9
# + 7
# .
# Example 1:
# Input:
# m = 1, n = 1
# Output:
# 3
# Explanation:
# The three possible colorings are shown in the image above.
# Example 2:
# Input:
# m = 1, n = 2
# Output:
# 6
# Explanation:
# The six possible colorings are shown in the image above.
# Example 3:
# Input:
# m = 5, n = 5
# Output:
# 580986
# Constraints:
# 1 <= m <= 5
# 1 <= n <= 1000

class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = 10**9 + 7
        colors = [0,1,2]
        states = []

        def validState(state):
            for i in range(1, len(state)):
                if state[i] == state[i - 1]:
                    return False
                
            return True

        for state in product(colors, repeat = m):
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
            


