# Link: https://leetcode.com/problems/find-the-original-typed-string-ii/description
# Description
# Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and
# may
# press a key for too long, resulting in a character being typed
# multiple
# times.
# You are given a string
# word
# , which represents the
# final
# output displayed on Alice's screen. You are also given a
# positive
# integer
# k
# .
# Return the total number of
# possible
# original strings that Alice
# might
# have intended to type, if she was trying to type a string of size
# at least
# k
# .
# Since the answer may be very large, return it
# modulo
# 10
# 9
# + 7
# .
# Example 1:
# Input:
# word = "aabbccdd", k = 7
# Output:
# 5
# Explanation:
# The possible strings are:
# "aabbccdd"
# ,
# "aabbccd"
# ,
# "aabbcdd"
# ,
# "aabccdd"
# , and
# "abbccdd"
# .
# Example 2:
# Input:
# word = "aabbccdd", k = 8
# Output:
# 1
# Explanation:
# The only possible string is
# "aabbccdd"
# .
# Example 3:
# Input:
# word = "aaabbb", k = 3
# Output:
# 8
# Constraints:
# 1 <= word.length <= 5 * 10
# 5
# word
# consists only of lowercase English letters.
# 1 <= k <= 2000

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        mod: int = 10**9 + 7

        island_sizes: list[int] = []
        tmp_count: int = 1
        for i in range(len(word) - 1):
            if word[i] == word[i+1]:
                tmp_count += 1
            else:
                island_sizes.append(tmp_count)
                tmp_count = 1
        island_sizes.append(tmp_count)

        total_number_of_words: int = 1
        for island_size in island_sizes:
            total_number_of_words *= island_size
            total_number_of_words %= mod

        if len(island_sizes) >= k:
            return total_number_of_words

        dp: list[list[int]] = [[0 for _ in range(k)] for _ in range(len(island_sizes) + 1)]  
        dp[0][0] = 1  

        for i in range(1, len(island_sizes) + 1):
            prefix_sum_dp_i_minus_1: list[int] = [
                0
            ] * (k + 1)  
            for j in range(k):
                prefix_sum_dp_i_minus_1[j+1] = (prefix_sum_dp_i_minus_1[j] + dp[i-1][j]) % mod

            for j in range(k):
                dp[i][j] = (prefix_sum_dp_i_minus_1[j] - prefix_sum_dp_i_minus_1[j - min(j, island_sizes[i-1])]) % mod


        return (total_number_of_words - sum(dp[len(island_sizes)][j] for j in range(k))) % mod

