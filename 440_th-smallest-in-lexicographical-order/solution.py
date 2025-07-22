# Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description
# Description
# Given two integers
# n
# and
# k
# , return
# the
# k
# th
# lexicographically smallest integer in the range
# [1, n]
# .
# Example 1:
# Input:
# n = 13, k = 2
# Output:
# 10
# Explanation:
# The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
# Example 2:
# Input:
# n = 1, k = 1
# Output:
# 1
# Constraints:
# 1 <= k <= n <= 10
# 9

class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def children(root, limit):
            ret, levelNodes, st = 0,1,root

            while st<= limit:
                ret += levelNodes
                levelNodes *= 10
                st *= 10

            levelNodes /= 10
            st /= 10
            ret -= levelNodes
            ret += abs(min(st + levelNodes, limit + 1) - st)

            return ret

        def funct(val, k, limit):
            if k == 1:
                return val

            nodes = children(val, limit)
            if nodes >= k:
                return funct(val * 10, k - 1, limit)
            else:
                return funct(val + 1, k - nodes, limit)
            
        return funct(1,k,n)
