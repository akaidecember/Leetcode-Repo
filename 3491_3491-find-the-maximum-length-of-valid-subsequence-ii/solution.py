# Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description
# Description
# You are given an integer array
# nums
# and a
# positive
# integer
# k
# .
# A
# subsequence
# sub
# of
# nums
# with length
# x
# is called
# valid
# if it satisfies:
# (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
# Return the length of the
# longest
# valid
# subsequence of
# nums
# .
# Example 1:
# Input:
# nums = [1,2,3,4,5], k = 2
# Output:
# 5
# Explanation:
# The longest valid subsequence is
# [1, 2, 3, 4, 5]
# .
# Example 2:
# Input:
# nums = [1,4,2,3,1,4], k = 3
# Output:
# 4
# Explanation:
# The longest valid subsequence is
# [1, 4, 1, 4]
# .
# Constraints:
# 2 <= nums.length <= 10
# 3
# 1 <= nums[i] <= 10
# 7
# 1 <= k <= 10
# 3

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[0] * k for _ in range(k)]
        maxi = 1
        for num in nums:
            currNum = num % k
            for mod in range(k):
                prevNum = (mod - currNum + k) % k
                dp[currNum][mod] = max(dp[currNum][mod] , 1 + dp[prevNum][mod])
                maxi = max(maxi , dp[currNum][mod])
        return maxi
