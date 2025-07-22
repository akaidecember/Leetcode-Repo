# Link: https://leetcode.com/problems/longest-consecutive-sequence/description
# Description
# Given an unsorted array of integers
# nums
# , return
# the length of the longest consecutive elements sequence.
# You must write an algorithm that runs in
# O(n)
# time.
# Example 1:
# Input:
# nums = [100,4,200,1,3,2]
# Output:
# 4
# Explanation:
# The longest consecutive elements sequence is
# [1, 2, 3, 4]
# . Therefore its length is 4.
# Example 2:
# Input:
# nums = [0,3,7,2,5,8,4,6,0,1]
# Output:
# 9
# Example 3:
# Input:
# nums = [1,0,1,2]
# Output:
# 3
# Constraints:
# 0 <= nums.length <= 10
# 5
# -10
# 9
# <= nums[i] <= 10
# 9

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)
        ret = 0

        for elem in st:
            if elem - 1 not in st:
                length = 1
                while elem + length in st:
                    length += 1

                ret = max(ret, length)

        return ret
