# Link: https://leetcode.com/problems/distribute-candies-among-children-ii/description
# Description
# You are given two positive integers
# n
# and
# limit
# .
# Return
# the
# total number
# of ways to distribute
# n
# candies among
# 3
# children such that no child gets more than
# limit
# candies.
# Example 1:
# Input:
# n = 5, limit = 2
# Output:
# 3
# Explanation:
# There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
# Example 2:
# Input:
# n = 3, limit = 3
# Output:
# 10
# Explanation:
# There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
# Constraints:
# 1 <= n <= 10
# 6
# 1 <= limit <= 10
# 6

class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        # Computes C(x,2) = x*(x-1)//2, or 0 if x<2
        def C2(x: int) -> int:
            return (x * (x - 1) // 2) if x >= 2 else 0

        total = (n+2)*(n+1)//2 # Count = C(n+2, 2)
        x1 = n - limit + 1     # Count with a > limit 
        t1 = C2(x1)

        x2 = n - 2 * limit     # Count with a > limit
        t2 = C2(x2)            # and b > limit

        x3 = n - 3 * limit - 1 # Count with a > limit
        t3 = C2(x3)            # b > limit, c > limit

        # Inclusion–exclusion
        return total - 3 * t1 + 3 * t2 - t3 
