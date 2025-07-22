# Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description
# Description
# You are given an array of strings
# words
# . Each element of
# words
# consists of
# two
# lowercase English letters.
# Create the
# longest possible palindrome
# by selecting some elements from
# words
# and concatenating them in
# any order
# . Each element can be selected
# at most once
# .
# Return
# the
# length
# of the longest palindrome that you can create
# . If it is impossible to create any palindrome, return
# 0
# .
# A
# palindrome
# is a string that reads the same forward and backward.
# Example 1:
# Input:
# words = ["lc","cl","gg"]
# Output:
# 6
# Explanation:
# One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
# Note that "clgglc" is another longest palindrome that can be created.
# Example 2:
# Input:
# words = ["ab","ty","yt","lc","cl","ab"]
# Output:
# 8
# Explanation:
# One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
# Note that "lcyttycl" is another longest palindrome that can be created.
# Example 3:
# Input:
# words = ["cc","ll","xx"]
# Output:
# 2
# Explanation:
# One longest palindrome is "cc", of length 2.
# Note that "ll" is another longest palindrome that can be created, and so is "xx".
# Constraints:
# 1 <= words.length <= 10
# 5
# words[i].length == 2
# words[i]
# consists of lowercase English letters.

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        # Create a counter for all words in the list
        hash = Counter(words)
        ret = 0
        
        # Iterate through the hashlist
        for word in list(hash):
            # Reverse the word and check if it is inverse
            rev = word[::-1]
            if word != rev:
                pair = min(hash[word], hash[rev])
                ret += pair * 4
                hash[word] -= pair
                hash[rev] -= pair
            # If it is not an inverse
            else:
                pair = hash[word] // 2
                ret += pair * 4
                hash[word] -= pair * 2
        
        # If the hash still has a pair with same cahr, add it in middle
        for word in hash:
            if word[0] == word[1] and hash[word] > 0:
                ret += 2
                break

        return ret
