# Link: https://leetcode.com/problems/valid-parentheses/description
# Description
# Given a string
# s
# containing just the characters
# '('
# ,
# ')'
# ,
# '{'
# ,
# '}'
# ,
# '['
# and
# ']'
# , determine if the input string is valid.
# An input string is valid if:
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
# Example 1:
# Input:
# s = "()"
# Output:
# true
# Example 2:
# Input:
# s = "()[]{}"
# Output:
# true
# Example 3:
# Input:
# s = "(]"
# Output:
# false
# Example 4:
# Input:
# s = "([])"
# Output:
# true
# Example 5:
# Input:
# s = "([)]"
# Output:
# false
# Constraints:
# 1 <= s.length <= 10
# 4
# s
# consists of parentheses only
# '()[]{}'
# .

class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)

        if n % 2 != 0:
            return False

        stk = []

        for c in s:
            if c == '(' or c == '{' or c == '[':
                stk.append(c)
            else:
                if stk:
                    temp = stk.pop()
                    if temp == '(' and c != ')':
                        return False
                    elif temp == '{' and c != '}':
                        return False
                    elif temp == '(' and c != ')':
                        return False
                else:
                    return False

        return len(stk) == 0

                    


        
