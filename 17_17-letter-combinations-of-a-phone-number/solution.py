# Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description
# Description
# Given a string containing digits from
# 2-9
# inclusive, return all possible letter combinations that the number could represent. Return the answer in
# any order
# .
# A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
# Example 1:
# Input:
# digits = "23"
# Output:
# ["ad","ae","af","bd","be","bf","cd","ce","cf"]
# Example 2:
# Input:
# digits = ""
# Output:
# []
# Example 3:
# Input:
# digits = "2"
# Output:
# ["a","b","c"]
# Constraints:
# 0 <= digits.length <= 4
# digits[i]
# is a digit in the range
# ['2', '9']
# .

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        pad, ret = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"], []

        n = len(digits)
        if n <= 0:
            return []

        def solver(i, strs):
            if i == len(digits):
                ret.append(strs)
                return
            
            for entry in pad[ord(digits[i]) - 48]:
                strs += entry
                solver(i + 1, strs)
                strs = strs[:-1]

        solver(0, "") 

        return ret

