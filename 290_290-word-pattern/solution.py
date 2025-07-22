# Link: https://leetcode.com/problems/word-pattern/description
# Description
# Given a
# pattern
# and a string
# s
# , find if
# s
# follows the same pattern.
# Here
# follow
# means a full match, such that there is a bijection between a letter in
# pattern
# and a
# non-empty
# word in
# s
# . Specifically:
# Each letter in
# pattern
# maps to
# exactly
# one unique word in
# s
# .
# Each unique word in
# s
# maps to
# exactly
# one letter in
# pattern
# .
# No two letters map to the same word, and no two words map to the same letter.
# Example 1:
# Input:
# pattern = "abba", s = "dog cat cat dog"
# Output:
# true
# Explanation:
# The bijection can be established as:
# 'a'
# maps to
# "dog"
# .
# 'b'
# maps to
# "cat"
# .
# Example 2:
# Input:
# pattern = "abba", s = "dog cat cat fish"
# Output:
# false
# Example 3:
# Input:
# pattern = "aaaa", s = "dog cat cat dog"
# Output:
# false
# Constraints:
# 1 <= pattern.length <= 300
# pattern
# contains only lower-case English letters.
# 1 <= s.length <= 3000
# s
# contains only lowercase English letters and spaces
# ' '
# .
# s
# does not contain
# any leading or trailing spaces.
# All the words in
# s
# are separated by a
# single space
# .

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        mp = {}
        ret1 = []

        for i,c in enumerate(pattern):
            if c not in mp:
                mp[c] = i
            ret1.append(str(mp[c]))

        mp2 = {}
        ret2 = []

        strList = s.split()
        for i,word in enumerate(strList):
            if word not in mp2:
                mp2[word] = i
            ret2.append(str(mp2[word]))

        return ret1 == ret2

