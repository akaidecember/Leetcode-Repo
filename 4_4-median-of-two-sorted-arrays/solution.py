# Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description
# Description
# Given two sorted arrays
# nums1
# and
# nums2
# of size
# m
# and
# n
# respectively, return
# the median
# of the two sorted arrays.
# The overall run time complexity should be
# O(log (m+n))
# .
# Example 1:
# Input:
# nums1 = [1,3], nums2 = [2]
# Output:
# 2.00000
# Explanation:
# merged array = [1,2,3] and median is 2.
# Example 2:
# Input:
# nums1 = [1,2], nums2 = [3,4]
# Output:
# 2.50000
# Explanation:
# merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
# Constraints:
# nums1.length == m
# nums2.length == n
# 0 <= m <= 1000
# 0 <= n <= 1000
# 1 <= m + n <= 2000
# -10
# 6
# <= nums1[i], nums2[i] <= 10
# 6

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        half = (n + m) // 2
        count, i, j = 0,0,0
        prev = curr = 0
        
        while count <= half:
            count += 1
            prev = curr
            if i < n and (j >= m or nums1[i] <= nums2[j]):
                curr = nums1[i]
                i += 1
            else:
                curr = nums2[j]
                j += 1
                
        if (m + n) % 2 == 0:
            return (prev + curr) / 2
        else:
            return curr
