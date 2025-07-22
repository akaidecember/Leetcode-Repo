# Link: https://leetcode.com/problems/zero-array-transformation-iii/description
# Description
# You are given an integer array
# nums
# of length
# n
# and a 2D array
# queries
# where
# queries[i] = [l
# i
# , r
# i
# ]
# .
# Each
# queries[i]
# represents the following action on
# nums
# :
# Decrement the value at each index in the range
# [l
# i
# , r
# i
# ]
# in
# nums
# by
# at most
# 1.
# The amount by which the value is decremented can be chosen
# independently
# for each index.
# A
# Zero Array
# is an array with all its elements equal to 0.
# Return the
# maximum
# number of elements that can be removed from
# queries
# , such that
# nums
# can still be converted to a
# zero array
# using the
# remaining
# queries. If it is not possible to convert
# nums
# to a
# zero array
# , return -1.
# Example 1:
# Input:
# nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
# Output:
# 1
# Explanation:
# After removing
# queries[2]
# ,
# nums
# can still be converted to a zero array.
# Using
# queries[0]
# , decrement
# nums[0]
# and
# nums[2]
# by 1 and
# nums[1]
# by 0.
# Using
# queries[1]
# , decrement
# nums[0]
# and
# nums[2]
# by 1 and
# nums[1]
# by 0.
# Example 2:
# Input:
# nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
# Output:
# 2
# Explanation:
# We can remove
# queries[2]
# and
# queries[3]
# .
# Example 3:
# Input:
# nums = [1,2,3,4], queries = [[0,3]]
# Output:
# -1
# Explanation:
# nums
# cannot be converted to a zero array even after using all the queries.
# Constraints:
# 1 <= nums.length <= 10
# 5
# 0 <= nums[i] <= 10
# 5
# 1 <= queries.length <= 10
# 5
# queries[i].length == 2
# 0 <= l
# i
# <= r
# i
# < nums.length

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n, q = len(nums), len(queries)
        starts = [[] for _ in range(n)]
        for l, r in queries:
            starts[l].append(r)

        avail = [] 
        active = []  
        chosen = 0
        for i in range(n):
            for r in starts[i]:
                heapq.heappush(avail, -r)

            while active and active[0] < i:
                heapq.heappop(active)

            need = nums[i] - len(active)
            for _ in range(need):
                while avail and -avail[0] < i:
                    heapq.heappop(avail)
                if not avail:
                    return -1
                r = -heapq.heappop(avail)
                heapq.heappush(active, r)
                chosen += 1
        return q - chosen
