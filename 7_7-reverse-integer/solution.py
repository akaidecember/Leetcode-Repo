# Link: https://leetcode.com/problems/reverse-integer/description
# Description
# Given a signed 32-bit integer
# x
# , return
# x
# with its digits reversed
# . If reversing
# x
# causes the value to go outside the signed 32-bit integer range
# [-2
# 31
# , 2
# 31
# - 1]
# , then return
# 0
# .
# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
# Example 1:
# Input:
# x = 123
# Output:
# 321
# Example 2:
# Input:
# x = -123
# Output:
# -321
# Example 3:
# Input:
# x = 120
# Output:
# 21
# Constraints:
# -2
# 31
# <= x <= 2
# 31
# - 1

class Solution:
    def reverse(self, x: int) -> int:
        sign = 1 if x >= 0 else -1
        reversed, x = 0, abs(x)

        while x:
            mod = x % 10
            x = x // 10
            reversed = reversed * 10 + mod
            if reversed > 2**31 - 1:
                return 0

        return sign * reversed
