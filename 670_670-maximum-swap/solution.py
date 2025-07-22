# Link: https://leetcode.com/problems/maximum-swap/description
# Description
# You are given an integer
# num
# . You can swap two digits at most once to get the maximum valued number.
# Return
# the maximum valued number you can get
# .
# Example 1:
# Input:
# num = 2736
# Output:
# 7236
# Explanation:
# Swap the number 2 and the number 7.
# Example 2:
# Input:
# num = 9973
# Output:
# 9973
# Explanation:
# No swap.
# Constraints:
# 0 <= num <= 10
# 8

# class Solution:
#     def maximumSwap(self, num: int) -> int:
#         freq = [0] * 10
#         s = list(str(num))

#         for i in range(len(s)):
#             freq[int(s[i])] = i

#         for i in range(len(s)):
#             for j in range(9, int(s[i]), -1):
#                 if freq[j] > i:
#                     s[i], s[freq[j]] = s[freq[j]], s[i]
#                     return int("".join(s))

#         return num

class Solution:
    def maximumSwap(self, num: int) -> int:
        a = list(str(num))
        n = len(a)
        left, right = -1, -1
        max_idx = n - 1
        for i in range(n - 2, -1, -1):
            if a[i] > a[max_idx]:
                max_idx = i
            elif a[i] < a[max_idx]:
                left, right = i, max_idx
        
        if left != -1:
            a[left], a[right] = a[right], a[left]
        
        return int(''.join(a))
