# Link: https://leetcode.com/problems/majority-element/description
# Description
# Given an array
# nums
# of size
# n
# , return
# the majority element
# .
# The majority element is the element that appears more than
# ⌊n / 2⌋
# times. You may assume that the majority element always exists in the array.
# Example 1:
# Input:
# nums = [3,2,3]
# Output:
# 3
# Example 2:
# Input:
# nums = [2,2,1,1,1,2,2]
# Output:
# 2
# Constraints:
# n == nums.length
# 1 <= n <= 5 * 10
# 4
# -10
# 9
# <= nums[i] <= 10
# 9
# Follow-up:
# Could you solve the problem in linear time and in
# O(1)
# space?

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count, candidate = 0, None

        for i in range(len(nums)):
            if count == 0:
                candidate = nums[i]
            if nums[i] == candidate:
                count += 1
            else:
                count -= 1

        return candidate
