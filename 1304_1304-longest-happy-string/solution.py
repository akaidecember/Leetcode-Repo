# Link: https://leetcode.com/problems/longest-happy-string/description
# Description
# A string
# s
# is called
# happy
# if it satisfies the following conditions:
# s
# only contains the letters
# 'a'
# ,
# 'b'
# , and
# 'c'
# .
# s
# does not contain any of
# "aaa"
# ,
# "bbb"
# , or
# "ccc"
# as a substring.
# s
# contains
# at most
# a
# occurrences of the letter
# 'a'
# .
# s
# contains
# at most
# b
# occurrences of the letter
# 'b'
# .
# s
# contains
# at most
# c
# occurrences of the letter
# 'c'
# .
# Given three integers
# a
# ,
# b
# , and
# c
# , return
# the
# longest possible happy
# string
# . If there are multiple longest happy strings, return
# any of them
# . If there is no such string, return
# the empty string
# ""
# .
# A
# substring
# is a contiguous sequence of characters within a string.
# Example 1:
# Input:
# a = 1, b = 1, c = 7
# Output:
# "ccaccbcc"
# Explanation:
# "ccbccacc" would also be a correct answer.
# Example 2:
# Input:
# a = 7, b = 1, c = 0
# Output:
# "aabaa"
# Explanation:
# It is the only correct answer in this case.
# Constraints:
# 0 <= a, b, c <= 100
# a + b + c > 0

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ca=cb=cc=0
        l=a+b+c
        r=[]
        for i in range(l):
            if (a>=b and a>=c and ca !=2) or (a>0 and (cb==2 or cc==2)):
                r.append('a')
                a-=1
                ca+=1
                cb=0
                cc=0
            elif (b>=c and b>=a and cb !=2) or (b>0 and (ca==2 or cc==2)):
                r.append('b')
                b-=1
                cb+=1
                ca=0
                cc=0
            elif (c>=b and c>=a and cc !=2) or (c>0 and (cb==2 or ca==2)):
                r.append('c')
                c-=1
                cc+=1
                cb=0
                ca=0
        return "".join(r)
