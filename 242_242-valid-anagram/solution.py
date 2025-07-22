# Link: https://leetcode.com/problems/valid-anagram/description
# Description
# Given two strings
# s
# and
# t
# , return
# true
# if
# t
# is an
# anagram
# of
# s
# , and
# false
# otherwise.
# Example 1:
# Input:
# s = "anagram", t = "nagaram"
# Output:
# true
# Example 2:
# Input:
# s = "rat", t = "car"
# Output:
# false
# Constraints:
# 1 <= s.length, t.length <= 5 * 10
# 4
# s
# and
# t
# consist of lowercase English letters.
# Follow up:
# What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1, freq2 = Counter(s), Counter(t)

        return freq1 == freq2
