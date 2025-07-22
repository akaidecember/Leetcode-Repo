# Link: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description
# Description
# You are given a string array
# words
# , and an array
# groups
# , both arrays having length
# n
# .
# The
# hamming distance
# between two strings of equal length is the number of positions at which the corresponding characters are
# different
# .
# You need to select the
# longest
# subsequence
# from an array of indices
# [0, 1, ..., n - 1]
# , such that for the subsequence denoted as
# [i
# 0
# , i
# 1
# , ..., i
# k-1
# ]
# having length
# k
# , the following holds:
# For
# adjacent
# indices in the subsequence, their corresponding groups are
# unequal
# , i.e.,
# groups[i
# j
# ] != groups[i
# j+1
# ]
# , for each
# j
# where
# 0 < j + 1 < k
# .
# words[i
# j
# ]
# and
# words[i
# j+1
# ]
# are
# equal
# in length, and the
# hamming distance
# between them is
# 1
# , where
# 0 < j + 1 < k
# , for all indices in the subsequence.
# Return
# a string array containing the words corresponding to the indices
# (in order)
# in the selected subsequence
# . If there are multiple answers, return
# any of them
# .
# Note:
# strings in
# words
# may be
# unequal
# in length.
# Example 1:
# Input:
# words = ["bab","dab","cab"], groups = [1,2,2]
# Output:
# ["bab","cab"]
# Explanation:
# A subsequence that can be selected is
# [0,2]
# .
# groups[0] != groups[2]
# words[0].length == words[2].length
# , and the hamming distance between them is 1.
# So, a valid answer is
# [words[0],words[2]] = ["bab","cab"]
# .
# Another subsequence that can be selected is
# [0,1]
# .
# groups[0] != groups[1]
# words[0].length == words[1].length
# , and the hamming distance between them is
# 1
# .
# So, another valid answer is
# [words[0],words[1]] = ["bab","dab"]
# .
# It can be shown that the length of the longest subsequence of indices that satisfies the conditions is
# 2
# .
# Example 2:
# Input:
# words = ["a","b","c","d"], groups = [1,2,3,4]
# Output:
# ["a","b","c","d"]
# Explanation:
# We can select the subsequence
# [0,1,2,3]
# .
# It satisfies both conditions.
# Hence, the answer is
# [words[0],words[1],words[2],words[3]] = ["a","b","c","d"]
# .
# It has the longest length among all subsequences of indices that satisfy the conditions.
# Hence, it is the only answer.
# Constraints:
# 1 <= n == words.length == groups.length <= 1000
# 1 <= words[i].length <= 10
# 1 <= groups[i] <= n
# words
# consists of
# distinct
# strings.
# words[i]
# consists of lowercase English letters.

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        adj = [[] for _ in range(n)]

        # Defining the hamming dist. fn.
        def hamming(w1, w2):
            n = len(w1)
            ret = 0
            return sum(w1[i] != w2[i] for i in range(n))

        # Since we need to find a subsequence, we care about the order, so we can create an 
        # adj. list like this.
        for i in range(n):
            for j in range(i + 1, n):
                if len(words[i]) != len(words[j]) or groups[i] == groups[j]:
                    continue
                if hamming(words[i], words[j]) == 1:
                    adj[i].append(j)

        dp = [1] * n
        prev = [-1] * n

        # For every words neighbor, choose the best (longest) path.
        for i in range(n):
            for j in adj[i]:
                if dp[j] < dp[i] + 1:
                    dp[j] = dp[i] + 1
                    prev[j] = i

        idx = max(range(n), key=lambda x: dp[x])
        ret = []

        # Rebuild the path backward.
        while idx != -1:
            ret.append(words[idx])
            idx = prev[idx]
        
        ret.reverse()
        return ret

