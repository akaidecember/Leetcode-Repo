# Link: https://leetcode.com/problems/longest-subsequence-repeated-k-times/description
# Description
# You are given a string
# s
# of length
# n
# , and an integer
# k
# . You are tasked to find the
# longest subsequence repeated
# k
# times in string
# s
# .
# A
# subsequence
# is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
# A subsequence
# seq
# is
# repeated
# k
# times in the string
# s
# if
# seq * k
# is a subsequence of
# s
# , where
# seq * k
# represents a string constructed by concatenating
# seq
# k
# times.
# For example,
# "bba"
# is repeated
# 2
# times in the string
# "bababcba"
# , because the string
# "bbabba"
# , constructed by concatenating
# "bba"
# 2
# times, is a subsequence of the string
# "
# b
# a
# bab
# c
# ba
# "
# .
# Return
# the
# longest subsequence repeated
# k
# times in string
# s
# . If multiple such subsequences are found, return the
# lexicographically largest
# one. If there is no such subsequence, return an
# empty
# string
# .
# Example 1:
# Input:
# s = "letsleetcode", k = 2
# Output:
# "let"
# Explanation:
# There are two longest subsequences repeated 2 times: "let" and "ete".
# "let" is the lexicographically largest one.
# Example 2:
# Input:
# s = "bb", k = 2
# Output:
# "b"
# Explanation:
# The longest subsequence repeated 2 times is "b".
# Example 3:
# Input:
# s = "ab", k = 2
# Output:
# ""
# Explanation:
# There is no subsequence repeated 2 times. Empty string is returned.
# Constraints:
# n == s.length
# 2 <= k <= 2000
# 2 <= n < min(2001, k * 8)
# s
# consists of lowercase English letters.

class Solution:
    def isKSubseq(self, sub, s, k):
        i = cnt = 0
        for ch in s:
            if ch == sub[i]:
                i += 1
                if i == len(sub):
                    cnt += 1
                    if cnt == k: return True
                    i = 0
        return False

    def longestSubsequenceRepeatedK(self, s, k):
        chars = [c for c, f in Counter(s).items() if f >= k]
        queue, best = deque([""]), ""
        while queue:
            curr = queue.popleft()
            for ch in chars:
                cand = curr + ch
                if self.isKSubseq(cand, s, k):
                    queue.append(cand)
                    if len(cand) > len(best) or (len(cand) == len(best) and cand > best):
                        best = cand
        return best
