# Link: https://leetcode.com/problems/sort-an-array/description
# Description
# Given an array of integers
# nums
# , sort the array in ascending order and return it.
# You must solve the problem
# without using any built-in
# functions in
# O(nlog(n))
# time complexity and with the smallest space complexity possible.
# Example 1:
# Input:
# nums = [5,2,3,1]
# Output:
# [1,2,3,5]
# Explanation:
# After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
# Example 2:
# Input:
# nums = [5,1,1,2,0,0]
# Output:
# [0,0,1,1,2,5]
# Explanation:
# Note that the values of nums are not necessarily unique.
# Constraints:
# 1 <= nums.length <= 5 * 10
# 4
# -5 * 10
# 4
# <= nums[i] <= 5 * 10
# 4

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(l, r):
            i, j = 0, 0
            nl, nr = len(l), len(r)
            ret = []

            while i < nl and j < nr:
                if l[i] < r[j]:
                    ret.append(l[i])
                    i += 1
                else:
                    ret.append(r[j])
                    j += 1

            ret.extend(l[i:])
            ret.extend(r[j:])

            return ret

        def mergeSort(nums):
            if len(nums) <= 1:
                return nums[:]

            mid = len(nums) // 2
            left = mergeSort(nums[:mid])
            right = mergeSort(nums[mid:])
            return merge(left, right)

        return mergeSort(nums)
