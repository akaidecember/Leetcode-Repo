# Link: https://leetcode.com/problems/russian-doll-envelopes/description
# Description
# You are given a 2D array of integers
# envelopes
# where
# envelopes[i] = [w
# i
# , h
# i
# ]
# represents the width and the height of an envelope.
# One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
# Return
# the maximum number of envelopes you can Russian doll (i.e., put one inside the other)
# .
# Note:
# You cannot rotate an envelope.
# Example 1:
# Input:
# envelopes = [[5,4],[6,4],[6,7],[2,3]]
# Output:
# 3
# Explanation:
# The maximum number of envelopes you can Russian doll is
# 3
# ([2,3] => [5,4] => [6,7]).
# Example 2:
# Input:
# envelopes = [[1,1],[1,1],[1,1]]
# Output:
# 1
# Constraints:
# 1 <= envelopes.length <= 10
# 5
# envelopes[i].length == 2
# 1 <= w
# i
# , h
# i
# <= 10
# 5

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes = sorted(envelopes, key=lambda x: (x[0], -x[1]))

        def lis(arr):
            def binarySearch(arr, x):
                low, high = 0, len(arr)
                while low < high:
                    mid = (low + high) // 2
                    if arr[mid] < x:
                        low = mid + 1
                    else:
                        high = mid
                return low

            subseq = []
            for elem in arr:
                i = binarySearch(subseq, elem)
                if i == len(subseq):
                    subseq.append(elem)
                else:
                    subseq[i] = elem

            return len(subseq)

        return lis([each[1] for each in envelopes])
                




