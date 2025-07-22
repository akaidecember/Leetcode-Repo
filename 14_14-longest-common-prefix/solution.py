# Link: https://leetcode.com/problems/longest-common-prefix/description
# Description
# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string
# ""
# .
# Example 1:
# Input:
# strs = ["flower","flow","flight"]
# Output:
# "fl"
# Example 2:
# Input:
# strs = ["dog","racecar","car"]
# Output:
# ""
# Explanation:
# There is no common prefix among the input strings.
# Constraints:
# 1 <= strs.length <= 200
# 0 <= strs[i].length <= 200
# strs[i]
# consists of only lowercase English letters if it is non-empty.

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        first, last, i = strs[0], strs[-1], 0
        ret = ''

        while i < min(len(first), len(last)):
            if first[i] == last[i]:
                ret += first[i]
            else:
                break

            i += 1

        return ret












